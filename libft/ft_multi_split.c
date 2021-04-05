/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:16:42 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/03/25 00:06:28 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check_char(char c, int n, char *chars)
{
	while (n--)
	{
		if (c == *(chars++))
			return (1);
	}
	return (0);
}

static int	size_split(char *str, int n, char *chars)
{
	int		count;

	count = 0;
	while (str[count] && !check_char(str[count], n, chars))
		count++;
	return (count);
}

char		**ft_multi_split(char *str, int n, char *chars)
{
	int		size;
	int		count;
	char	**res;

	count = 0;
	size = 0;
	while (str[count])
	{
		if (!check_char(str[count], n, chars)
				&& (!count || check_char(str[count - 1], n, chars)))
			size++;
		count++;
	}
	if (!(res = malloc((size + 1) * sizeof(char *))))
		return (NULL);
	res[size] = 0;
	size = 0;
	count = -1;
	while (str[++count])
		if (!check_char(str[count], n, chars)
				&& (!count || check_char(str[count - 1], n, chars)))
			res[size++] = ft_strndup(&str[count], size_split(&str[count], n,
						chars));
	return (res);
}
