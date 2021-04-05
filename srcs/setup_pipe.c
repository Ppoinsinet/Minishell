/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:18:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:26:48 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					setup_pipe(t_pipe *pipe, int type, char *arg)
{
	clear_pipe(pipe);
	clear_pipe(pipe);
	pipe->type = type;
	pipe->arg = arg;
	if (arg)
	{
		if (type == APPEND)
			pipe->fd = open(arg, O_CREAT | O_APPEND | O_WRONLY, 0666);
		else if (type == WRITE)
			pipe->fd = open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		else if (type == READ)
			pipe->fd = open(arg, O_RDONLY);
		if (pipe->fd == -1)
		{
			ft_printf("Shell42 : %s: %s\n", arg, strerror(errno));
			return (1);
		}
	}
	else
		pipe->fd = -1;
	return (0);
}

int					define_pipes(char **tmp, int count, int **pipetoread,
		int **pipetowrite)
{
	char			*input;

	input = NULL;
	while (++count < g_shell.number_of_pipes && tmp[count])
	{
		if (find_pipe(tmp[count]) == -1)
			break ;
		if (count != g_shell.number_of_pipes - 1 && g_shell.stdout.type == NONE)
		{
			g_shell.stdout.fd = **pipetowrite;
			*pipetowrite += 2;
		}
		if (count && g_shell.stdin.type == NONE)
		{
			g_shell.stdin.fd = **pipetoread;
			*pipetoread += 2;
		}
		if (tmp[count])
		{
			tmp[count] = delete_pipes(tmp[count]);
			manage_exec(treat_args(ft_shell_split(tmp[count], ' ')));
		}
	}
	return (close_pipes());
}

int					manage_pipe(char *cmd)
{
	char			**tmp;
	int				count;
	int				*pipetoread;
	int				*pipetowrite;

	g_shell.number_of_pipes = 0;
	tmp = ft_shell_split(cmd, '|');
	while (tmp[g_shell.number_of_pipes])
		g_shell.number_of_pipes++;
	g_shell.pipes = malloc((g_shell.number_of_pipes * 2) * sizeof(int));
	count = 0;
	while (count < g_shell.number_of_pipes * 2)
	{
		pipe(&g_shell.pipes[count]);
		count += 2;
	}
	pipetoread = &g_shell.pipes[0];
	pipetowrite = &g_shell.pipes[1];
	define_pipes(tmp, -1, &pipetoread, &pipetowrite);
	if (tmp)
		free_split(&tmp);
	while (wait(&g_shell.exit_status) > 0)
		;
	return (0);
}
