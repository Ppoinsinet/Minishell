/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:46:08 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/12/01 16:10:40 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_calloc(size_t nmemb, size_t size)
{
	char				*result;
	unsigned int		count;

	if (!size || !nmemb)
		return (ft_strdup(""));
	if (!(result = malloc(size * nmemb)))
		return (NULL);
	count = 0;
	while (count < nmemb * size)
	{
		result[count] = 0;
		count++;
	}
	return ((void *)result);
}
