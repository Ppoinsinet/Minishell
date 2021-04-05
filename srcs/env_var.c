/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:18:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 16:21:48 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					gives_var_size(char *str)
{
	int				count;

	count = 1;
	while (str[count] && str[count] > 32 && str[count] != '\''
			&& str[count] != '\"' && str[count] != '@' && str[count] != '\\'
			&& str[count] != '/')
		count++;
	return (count);
}

static char			*treat_var_two(char *input, char *tmp, int *index, int size)
{
	char			*buf;
	char			*tmp_;

	tmp_ = NULL;
	buf = ft_strndup(tmp, size);
	if (buf && *buf)
		tmp_ = get_env_var(buf + 1);
	*index = (tmp - input);
	if (buf)
		free(buf);
	return (tmp_);
}

int					treat_var(char **tmp, char **input, int size)
{
	char			*tmp_;
	char			*buf;
	int				index;

	if (*tmp && ((*tmp)[1] == '$' || (*tmp)[1] == '?'))
	{
		tmp_ = (*tmp)[1] == '?' ?
			ft_itoa(g_shell.exit_status) : ft_itoa(getpid());
		*input = ft_strremove(*input, (*tmp - *input), 2);
		*input = ft_strinsert(*input, tmp_, (*tmp - *input));
		free(tmp_ ? tmp_ : NULL);
	}
	else if ((size = gives_var_size(*tmp)) > 1)
	{
		tmp_ = treat_var_two(*input, *tmp, &index, size);
		*input = ft_strremove(*input, index, size);
		*tmp = &(*input)[index];
		if (tmp_ && ft_strchr(tmp_, '='))
			*input = ft_strinsert(*input, ft_strchr(tmp_, '=') + 1, (*tmp
						- *input));
		free(tmp_ ? tmp_ : NULL);
	}
	else
		return (1);
	return (0);
}

char				*env_var_input(char *input)
{
	char			*tmp;
	int				index;

	if (!ft_strchr(input, '$'))
		return (input);
	tmp = input;
	while (*tmp && (tmp = ft_strchr(tmp, '$')))
	{
		index = (tmp - input);
		if (is_contained_between(input, tmp, "\'", "\'") == -1
				&& (!index || *(tmp - 1) != '\\'))
		{
			if (!treat_var(&tmp, &input, 0))
				;
			else
				index++;
		}
		else
			index++;
		tmp = &input[(int)ft_strlen(input) > index ? index : ft_strlen(input)];
	}
	return (input);
}

char				**gives_path_var(void)
{
	char			*tmp;
	char			**paths;

	if (!(tmp = getenv("PATH")))
		return (NULL);
	else if (!(paths = ft_split(tmp, ':')))
		return (NULL);
	return (paths);
}
