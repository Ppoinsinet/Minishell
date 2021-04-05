/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:47:13 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/19 00:59:53 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	count;

	count = -1;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		while (++count < n)
			*((char *)(dest + count)) = *((char *)(src + count));
	else
		while (n-- > 0)
			*((char *)(dest + n)) = *((char *)(src + n));
	return (dest);
}
