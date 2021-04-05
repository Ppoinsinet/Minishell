/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:17:11 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/03/17 13:17:11 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*extract_str(char *str)
{
	char			*res;
	int				count;
	int				index;

	index = 0;
	count = 0;
	while (str[index] && (str[index] == ' ' || str[index] == '\t'
				|| str[index] == '\n'))
		index++;
	while (str[index + count] && str[index + count] != ' '
			&& str[index + count] != '\t' && str[index + count] != '\n')
		count++;
	if (!(res = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ft_strncpy(res, &str[index], count);
	res[count] = 0;
	return (res);
}
