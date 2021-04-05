/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:36:53 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 18:23:46 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			is_contained_three(char *str, char *tmp, int *count,
		int *result)
{
	if (*count && ((str - tmp) == 0 || *(str - 1) != '\\'))
	{
		*count -= 1;
		*result = -1;
	}
}

static void			is_contained_two(char **str, int *count, char *c1,
		int *result)
{
	*result = *count;
	(*count)++;
	*str += ft_strlen(c1) - 1;
}

int					is_contained_between(char *str, char *index, char *c1,
		char *c2)
{
	int				count;
	int				result;
	char			*tmp;

	count = 0;
	tmp = str;
	str--;
	while (++str && *str && c1 && *c1)
		if (str == index)
		{
			if (!ft_strncmp(c2, str, ft_strlen(c2)))
				is_contained_three(str, tmp, &count, &result);
			return (count > 0 ? result : -1);
		}
		else if (!count && !ft_strncmp(c1, str, ft_strlen(c1)) && ((str -
						tmp) == 0 || *(str - 1) != '\\'))
			is_contained_two(&str, &count, c1, &result);
		else if (count && !ft_strncmp(c2, str, ft_strlen(c2)) && ((str -
						tmp) == 0 || *(str - 1) != '\\'))
		{
			result = -1;
			count--;
			str += ft_strlen(c2) - 1;
		}
	return (0);
}

char				is_between_guill(char *str, char *tmp)
{
	int				tmp__;
	int				tmp_;

	tmp__ = is_contained_between(str, tmp, "'", "'");
	tmp_ = is_contained_between(str, tmp, "\"", "\"");
	if (tmp__ < 0 && tmp_ < 0)
		return (0);
	if (tmp__ >= tmp_ && tmp_ > -1)
		return ('\"');
	else if (tmp_ >= tmp__ && tmp__ > -1)
		return ('\'');
	return (tmp_ > tmp__ ? tmp__ : tmp_);
}

int					size_word(char *str)
{
	int				size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] && str[size] != ' ' && str[size] != '\t'
			&& str[size] != '\n')
		size++;
	return (size);
}
