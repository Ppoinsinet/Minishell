/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:49:23 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 16:52:09 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	taille;
	size_t	count;

	if (!(*s2))
		return ((char *)s1);
	taille = ft_strlen(s2);
	count = 0;
	while (s1[count] && count < len)
	{
		if (!ft_strncmp((char *)&s1[count], (char *)s2, taille))
		{
			if (count + taille <= len)
				return ((char *)&s1[count]);
		}
		count++;
	}
	return (NULL);
}
