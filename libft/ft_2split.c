/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/01/29 17:43:53 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_strlenc(const char *s, char c, char c2)
{
	int				count;

	count = 0;
	while (s[count] && s[count] != c && s[count] != c2)
		count++;
	return (count);
}

static int			count_cases(char *s, char c, char c2)
{
	size_t			count;
	int				cases;

	cases = 0;
	count = 0;
	while (count < ft_strlen((char *)s))
	{
		if (s[count] != c && s[count] != c2 && (count == 0 || s[count - 1] == c
					|| s[count - 1] == c2))
			cases++;
		count++;
	}
	return (cases);
}

int					free_split(char ***split)
{
	int				count;

	count = 0;
	if (!split || !*split)
		return (1);
	while ((*split)[count])
	{
		free((*split)[count]);
		count++;
	}
	free(*split);
	*split = NULL;
	return (0);
}

char				**ft_2split(char const *s, char c, char c2)
{
	int				cases;
	unsigned int	i;
	char			**result;

	cases = count_cases((char *)s, c, c2);
	if (!(result = malloc((cases + 1) * sizeof(char *))))
		return (NULL);
	result[cases] = NULL;
	i = -1;
	cases = 0;
	while (++i < ft_strlen((char *)s))
		if (s[i] != c && s[i] != c2 && (i == 0 || s[i - 1] == c
					|| s[i - 1] == c2))
		{
			if (!(result[cases] = malloc(sizeof(char) *
							(ft_strlenc(&s[i], c, c2) + 1))))
			{
				while (--cases >= 0)
					free(result[cases]);
				free(result);
				return (NULL);
			}
			ft_strlcpy(result[cases++], &s[i], ft_strlenc(&s[i], c, c2) + 1);
		}
	return (result);
}
