/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:22:04 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:54:52 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strreplace(char *str, char *to_remove, char *to_replace)
{
	char			*tmp;
	int				index;

	tmp = str;
	index = 0;
	if (!*to_remove)
		return (str);
	while ((tmp = ft_strstr(tmp, to_remove)))
	{
		index = (int)(tmp - str);
		str = ft_strremove(str, index, ft_strlen(to_remove));
		str = ft_strinsert(str, to_replace, index);
		index += ft_strlen(to_replace);
		tmp = &str[index];
	}
	return (str);
}
