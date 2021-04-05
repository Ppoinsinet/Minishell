/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:15:59 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:24:08 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					exec_bin_script(char **cmd)
{
	struct stat		buf;
	int				id;

	if (!ft_strchr(cmd[0], '/') || stat(cmd[0], &buf) != 0)
		return (1);
	if ((buf.st_mode & S_IFREG))
	{
		if (!(buf.st_mode & S_IXUSR))
			ft_printf(PERMISSION_ERROR);
		if ((id = fork()) == -1)
			return (2);
		if (id)
		{
			wait((int *)&g_shell.exit_status);
			return (0);
		}
		duplicate_pipes();
		execve(cmd[0], cmd + 1, g_shell.env);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int					running_bin(char **cmd)
{
	char			**paths;
	char			*tmp;
	int				count;

	if (!(paths = gives_path_var()))
		return (ft_printf("Shell42: couldn't get PATH variable\n"));
	count = -1;
	while (paths[++count])
		if (!find_dir(paths[count], *cmd))
		{
			tmp = ft_strjoin_free_two(paths[count], ft_strjoin("/", *cmd));
			if (!cmd[1])
				add_env_var(ft_strjoin("_=", tmp));
			if (fork())
			{
				free(tmp);
				break ;
			}
			duplicate_pipes();
			if (execve(tmp, cmd, g_shell.env) == -1)
				exit(ft_printf("Shell42 : %s:  %s\n", *cmd, strerror(errno)));
		}
	!paths[count] ? ft_printf("Shell42 : %s: command not found\n", *cmd) : 0;
	free_split(&paths);
	return (-1);
}

void				manage_exec_two(char **cmd)
{
	add_dyn_variable(cmd);
	if (!exec_bin_script(cmd))
		;
	else if (!ft_strcmp(cmd[0], "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp(cmd[0], "env"))
		ft_env();
	else if (!ft_strcmp(cmd[0], "export"))
		ft_export(cmd + 1);
	else if (!ft_strcmp(cmd[0], "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp(cmd[0], "unset"))
		ft_unset(cmd + 1);
	else if (!ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd + 1);
	else if (!ft_strcmp(cmd[0], "clear"))
		tputs(tgetstr("cl", NULL), 1, myputchar);
	else if (**cmd != '.')
		running_bin(cmd);
	else
		ft_printf("Shell42 : %s: command not found\n", *cmd);
}

int					manage_exec(char **cmd)
{
	if (!cmd || !*cmd)
		return (1);
	if (!ft_strcmp(cmd[0], "exit"))
	{
		free_split(&cmd);
		free_shell();
		exit(EXIT_SUCCESS);
	}
	if (!*cmd)
		exit(EXIT_SUCCESS);
	else
		manage_exec_two(cmd);
	free_split(&cmd);
	return (EXIT_SUCCESS);
}
