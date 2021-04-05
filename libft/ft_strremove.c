/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:10:05 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 16:10:14 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strremove(char *str, int index, int rem)
{
	int				length;
	char			*result;

	length = 0;
	if (!str || !rem || index < 0 || index > (int)ft_strlen(str))
		return (NULL);
	if (index < 0 || index > (int)ft_strlen(str))
		return (str);
	while (str[length])
		length++;
	if (!length)
	{
		free(str);
		return (ft_strdup(""));
	}
	if (!(result = ft_calloc(sizeof(char), (length + 1 - rem))))
		return (NULL);
	result[length - rem] = 0;
	ft_strncpy(result, str, index);
	if (index + rem < (int)ft_strlen(str))
		ft_strncpy(result + index, str + index + rem, length - index - rem);
	free(str);
	return (result);
}
