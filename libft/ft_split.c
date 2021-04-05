/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/01/25 14:21:39 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strlenc(const char *s, char c)
{
	int				count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static int			count_cases(char *s, char c)
{
	size_t			count;
	int				cases;

	cases = 0;
	count = 0;
	while (count < ft_strlen((char *)s))
	{
		if (s[count] != c && (count == 0 || s[count - 1] == c))
			cases++;
		count++;
	}
	return (cases);
}

char				**ft_split(char const *s, char c)
{
	int				cases;
	unsigned int	i;
	char			**result;

	cases = count_cases((char *)s, c);
	if (!(result = malloc((cases + 1) * sizeof(char *))))
		return (NULL);
	result[cases] = NULL;
	i = -1;
	cases = 0;
	while (++i < ft_strlen((char *)s))
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			if (!(result[cases] = malloc(sizeof(char) *
							(ft_strlenc(&s[i], c) + 1))))
			{
				while (--cases >= 0)
					free(result[cases]);
				free(result);
				return (NULL);
			}
			ft_strlcpy(result[cases++], &s[i], ft_strlenc(&s[i], c) + 1);
		}
	return (result);
}
