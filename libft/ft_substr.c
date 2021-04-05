/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:45 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/17 18:21:44 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	count;

	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	if (!(result = malloc(len * sizeof(char) + 1)))
		return (NULL);
	count = 0;
	while (count < len && s[count + start])
	{
		result[count] = s[count + start];
		count++;
	}
	result[count] = 0;
	return (result);
}
