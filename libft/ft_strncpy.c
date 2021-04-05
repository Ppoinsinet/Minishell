/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:21:44 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/03/27 23:45:53 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;
	char			end;

	end = 0;
	count = 0;
	while (count < n)
	{
		if (!end && !src[count])
			end = 1;
		if (!end)
			dest[count] = src[count];
		else
			dest[count] = 0;
		count++;
	}
	return (dest);
}
