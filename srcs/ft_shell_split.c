/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 21:48:39 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_strlenc(char *s, char c)
{
	int				count;

	count = 0;
	while (s[count] && (s[count] != c || s[count] == '\'' || s[count] == '\"'
				|| (s[count] == c && is_between_guill(s, &s[count]))))
		count++;
	return (count);
}

static int			count_cases(char *s, char c)
{
	size_t			count;
	int				cases;

	cases = 0;
	count = 0;
	while (count < ft_strlen(s))
	{
		if (count == 0 && s[count] != c)
		{
			cases++;
		}
		else if (s[count] != c && s[count - 1] == c
				&& !is_between_guill(s, &s[count - 1]))
		{
			cases++;
		}
		count++;
	}
	return (cases);
}

static char			**save_str(char **result, char *str, char c, int *cases)
{
	if (!str)
		return (0);
	if (!(result[*cases] = ft_calloc(sizeof(char),
					(ft_strlenc(str, c) + 1))))
	{
		while (--(*cases) >= 0)
			free(result[*cases]);
		free(result);
		return (NULL);
	}
	ft_strlcpy((result[*cases]), str, ft_strlenc(str, c) + 1);
	(*cases)++;
	return (result);
}

char				**ft_shell_split(char const *s, char c)
{
	int				cases;
	unsigned int	i;
	char			**result;

	cases = count_cases((char *)s, c);
	if (!(result = ft_calloc((cases + 1), sizeof(char *))))
		return (NULL);
	i = -1;
	cases = 0;
	while (++i < ft_strlen((char *)s))
	{
		if (!i && s[i] != c)
		{
			if (!(result = save_str(result, (char *)&s[i], c, &cases)))
				return (NULL);
		}
		else if (s[i] != c && s[i - 1] == c && !is_between_guill((char *)s,
					(char *)&s[i - 1]))
		{
			if (!(result = save_str(result, (char *)&s[i], c, &cases)))
				return (NULL);
		}
	}
	return (result);
}
