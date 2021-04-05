/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:49:28 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 16:12:26 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *add;

	add = NULL;
	while (*s)
	{
		if (*s == c)
			add = (char *)s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return (add);
}
