/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:47:02 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 16:08:25 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	count;

	if (!dest && !src)
		return (dest);
	count = 0;
	while (count < n)
	{
		*((char *)(dest + count)) = *((char *)(src + count));
		count++;
	}
	return (dest);
}
