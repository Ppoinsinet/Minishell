/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:20 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 02:11:13 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					close_pipes(void)
{
	int				count;

	if (!g_shell.pipes)
		return (0);
	count = -1;
	while (++count < g_shell.number_of_pipes * 2)
	{
		close(g_shell.pipes[count]);
		if (g_shell.stdin.fd == g_shell.pipes[count])
			g_shell.stdin.fd = -1;
		if (g_shell.stdout.fd == g_shell.pipes[count])
			g_shell.stdout.fd = -1;
	}
	if (g_shell.pipes)
	{
		free(g_shell.pipes);
		g_shell.pipes = NULL;
	}
	if (g_shell.stdout.fd > -1)
		close(g_shell.stdout.fd);
	if (g_shell.stdin.fd > -1)
		close(g_shell.stdin.fd);
	g_shell.stdin.fd = -1;
	g_shell.stdout.fd = -1;
	return (0);
}

int					clear_pipe(t_pipe *pipe)
{
	pipe->type = NONE;
	if (pipe->fd > -1)
		close(pipe->fd);
	pipe->fd = -1;
	if (pipe->arg)
	{
		free(pipe->arg);
		pipe->arg = NULL;
	}
	return (0);
}

int					init_pipe(t_pipe *pipe)
{
	pipe->type = NONE;
	pipe->fd = -1;
	pipe->arg = NULL;
	return (0);
}

char				*next_word(char *str)
{
	while (str && *str && *str > 32 && *str < 127)
		str++;
	while (str && *str && (*str == ' ' || *str == '\t' || *str == '\n'))
		str++;
	if (!str || !*str)
		return (NULL);
	return (str);
}

char				*previous_word(char *str, int index)
{
	while (index >= 0)
	{
		if (str[index] > 32 && str[index] < 127)
			if (!index || (str[index - 1] <= 32 || str[index - 1] == 127))
				return (&str[index]);
		index--;
	}
	return (NULL);
}
