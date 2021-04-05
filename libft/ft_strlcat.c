/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:48:53 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/19 01:26:06 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	count;
	unsigned int	count2;
	int				tailledst;

	tailledst = ft_strlen(dst);
	count2 = 0;
	count = tailledst;
	if (size < count + 1)
		return (size + ft_strlen(src));
	while (count + 1 < size && src[count2])
	{
		dst[count] = src[count2];
		count++;
		count2++;
	}
	dst[count] = 0;
	return (tailledst + ft_strlen(src));
}
