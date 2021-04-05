/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:48:48 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 16:16:10 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*result;
	int		count;

	count = 0;
	if (!(result = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[count])
	{
		result[count] = s[count];
		count++;
	}
	result[count] = 0;
	return (result);
}
