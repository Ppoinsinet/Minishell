/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:46:42 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 16:33:43 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int count;

	count = 0;
	while (count < n)
	{
		*((char *)(dest + count)) = *((char *)(src + count));
		if (*((char *)(src + count)) == (char)c)
			return (dest + count + 1);
		count++;
	}
	return (NULL);
}
