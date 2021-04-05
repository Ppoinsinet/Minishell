/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:10:05 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:44:02 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcpy(char *dest, char *src)
{
	int				count;

	count = -1;
	while (src[++count])
		dest[count] = src[count];
	dest[count] = 0;
	return (dest);
}
