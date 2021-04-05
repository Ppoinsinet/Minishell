/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:37 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 23:41:17 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	taille;
	char	*result;
	int		count;

	taille = ft_strlen((char *)s);
	if (!(result = malloc((taille + 1) * sizeof(char))))
		return (NULL);
	result[taille] = 0;
	count = 0;
	while (s[count])
	{
		result[count] = (*f)(count, s[count]);
		count++;
	}
	return (result);
}
