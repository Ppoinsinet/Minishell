/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:10:05 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 16:22:25 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strinsert(char *str, char *str2, int index)
{
	int				length;
	int				length2;
	char			*result;

	length = ft_strlen(str);
	length2 = ft_strlen(str2);
	if (!length)
	{
		if (str)
			free(str);
		return (ft_strdup(str2));
	}
	else if (!length2)
		return (str);
	if (!(result = ft_calloc(sizeof(char), (length + 1 + length2))))
		return (NULL);
	result[length + length2] = 0;
	ft_strncpy(result, str, index);
	ft_strncpy(result + index, str2, length2);
	ft_strncpy(result + index + length2, str + index, length - index);
	free(str);
	return (result);
}

char				*ft_strinsert_free(char *str, char *str2, int index)
{
	int				length;
	int				length2;
	char			*result;

	length = ft_strlen(str);
	length2 = ft_strlen(str2);
	if (!length)
	{
		free(str);
		return (str2);
	}
	else if (!length2)
	{
		free(str2);
		return (str);
	}
	if (!(result = ft_calloc(sizeof(char), (length + 1 + length2))))
		return (NULL);
	result[length + length2] = 0;
	ft_strncpy(result, str, index);
	ft_strncpy(result + index, str2, length2);
	ft_strncpy(result + index + length2, str + index, length - index);
	free(str2);
	free(str);
	return (result);
}
