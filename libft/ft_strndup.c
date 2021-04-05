/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:49:59 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/03/25 21:10:12 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strndup(const char *s, size_t n)
{
	char			*result;
	unsigned int	count;

	count = 0;
	if (!s)
		return (NULL);
	if (!(result = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s[count] && count < n)
	{
		result[count] = s[count];
		count++;
	}
	while (count < n)
	{
		result[count] = 0;
		count++;
	}
	result[count] = 0;
	return (result);
}
