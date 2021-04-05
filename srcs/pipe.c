/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:20 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 21:54:37 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*pipe_next_word(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str > 32 && *str < 127 && *str != '<' && *str != '>'
				&& *str != '|')
			break ;
		str++;
	}
	return (*str ? str : NULL);
}

void				find_pipe_two(char *str, int *count)
{
	if (!ft_check_pipe(str, ">>"))
	{
		setup_pipe(&g_shell.stdout, APPEND, ft_strndup(pipe_next_word(str + 2),
					size_word(pipe_next_word(str + 2))));
		(*count)++;
	}
	else if (!ft_check_pipe(str, ">"))
	{
		setup_pipe(&g_shell.stdout, WRITE, ft_strndup(pipe_next_word(str + 1),
					size_word(pipe_next_word(str + 1))));
	}
	else if (!ft_check_pipe(str, "<"))
	{
		setup_pipe(&g_shell.stdin, READ, ft_strndup(pipe_next_word(str + 1),
					size_word(pipe_next_word(str + 1))));
	}
	if (((g_shell.stdout.fd < 0 || !g_shell.stdout.arg) && g_shell.stdout.type
				!= NONE) || ((g_shell.stdin.fd < 0 || !g_shell.stdin.arg)
					&& g_shell.stdin.type != NONE))
	{
		clear_pipe(&g_shell.stdin);
		clear_pipe(&g_shell.stdout);
		g_shell.stdin.type = ERROR;
		g_shell.stdout.type = ERROR;
	}
}

int					find_pipe(char *str)
{
	int				count;

	count = -1;
	clear_pipe(&g_shell.stdout);
	clear_pipe(&g_shell.stdin);
	while (str[++count] && g_shell.stdin.type != ERROR)
	{
		if (is_between_guill(str, &str[count])
				|| (count > 0 && str[count - 1] == '\\'))
			continue;
		find_pipe_two(&str[count], &count);
	}
	if (g_shell.stdin.type == ERROR)
		return (-1);
	return (0);
}

int					duplicate_pipes(void)
{
	if (g_shell.stdin.fd != -1)
	{
		dup2(g_shell.stdin.fd, STDIN_FILENO);
		close(g_shell.stdin.fd);
	}
	if (g_shell.stdout.fd != -1)
	{
		dup2(g_shell.stdout.fd, STDOUT_FILENO);
		close(g_shell.stdout.fd);
	}
	close_pipes();
	return (0);
}
