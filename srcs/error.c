/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 21:58:16 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:23:03 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char			check_pipe_arg_two(char **tmp)
{
	if (is_between_guill(g_shell.input, &g_shell.input[(int)(*tmp -
					g_shell.input)]))
	{
		(*tmp)++;
		return (0);
	}
	if (!*tmp || ((!(*tmp = pipe_next_word(*tmp)))))
		return (-1);
	return (1);
}

char				check_pipe_arg(void)
{
	char			*tmp;
	int				temp;

	tmp = g_shell.input;
	while ((tmp = ft_strstr(tmp, "<")))
	{
		if (!(temp = check_pipe_arg_two(&tmp)))
			continue;
		else if (temp == -1)
			return (-1);
		tmp++;
	}
	tmp = g_shell.input;
	while ((tmp = ft_strstr(tmp, ">")))
	{
		if (!(temp = check_pipe_arg_two(&tmp)))
			continue;
		else if (temp == -1)
			return (-1);
		tmp++;
	}
	return (0);
}

char				check_pipe_format(void)
{
	char			*tmp;

	tmp = g_shell.input;
	while ((tmp = ft_strstr(tmp, "<")))
	{
		if (is_between_guill(g_shell.input, tmp) && tmp++)
			continue ;
		if (ft_check_pipe(tmp, "<"))
			return (-1);
		tmp++;
	}
	tmp = g_shell.input;
	while ((tmp = ft_strstr(tmp, ">")))
	{
		if (is_between_guill(g_shell.input, tmp) && tmp++)
			continue ;
		if (ft_check_pipe(tmp, ">>") && ft_check_pipe(tmp, ">"))
			return (-1);
		tmp += !ft_check_pipe(tmp, ">>") ? 2 : 1;
	}
	return (0);
}

int					check_input(void)
{
	if (check_pipe_arg())
		return (ft_printf("Shell42: parsing error n°1\n"));
	if (check_pipe_format())
		return (ft_printf("Shell42: parsing error n°2\n"));
	return (0);
}

char				ft_check_pipe(char *str, char *str2)
{
	int				len;

	len = ft_strlen(str2);
	if (ft_strncmp(str, str2, len))
		return (1);
	if (str[len] == '<' || str[len] == '>' || str[len] == '|')
		return (2);
	return (0);
}
