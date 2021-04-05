/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:15:27 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:21:06 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_pwd(char **cmd)
{
	char			buff[2048];

	if (cmd[1])
		return (ft_printf("pwd : trop d'arguments\n"));
	if (!fork())
	{
		duplicate_pipes();
		printf("%s\n", getcwd(buff, 2048));
		exit(EXIT_SUCCESS);
	}
	else
		wait(&g_shell.exit_status);
	return (0);
}

char				*clear_space_export(char *s)
{
	char			*tmp;
	int				count;

	tmp = ft_strrchr(s, ' ');
	count = (int)(tmp - s);
	while (count > 0 && s[count] == ' ' && s[count - 1] == ' ')
	{
		s[count] = 0;
		count--;
	}
	return (s);
}

int					ft_export(char **cmd)
{
	char			**tmp;
	char			*str;
	int				count;

	count = 0;
	if (!cmd[0])
	{
		tmp = sort_env(g_shell.env);
		while (tmp[count])
		{
			str = ft_strndup(tmp[count], size_until(tmp[count], '='));
			printf("declare -x %s=\"%s\"\n", str, ft_strchr(tmp[count], '=')
					+ 1);
			free(str);
			count++;
		}
	}
	else
		add_env_var(clear_space_export(ft_strdup(cmd[0])));
	return (0);
}

int					ft_unset(char **cmd)
{
	int				count;
	char			**tmp;

	tmp = NULL;
	while (*cmd)
	{
		count = 0;
		while (g_shell.env[count])
		{
			if (!ft_strncmp(g_shell.env[count], *cmd,
						size_until(g_shell.env[count], '=')))
			{
				if (!(tmp = env_remove(g_shell.env, *cmd)))
					return (0);
				free(g_shell.env);
				g_shell.env = tmp;
				break ;
			}
			count++;
		}
		cmd++;
	}
	return (0);
}

int					ft_echo(char **cmd)
{
	int				count;
	char			skip;

	if (fork())
		return (0);
	duplicate_pipes();
	skip = 0;
	count = -1;
	while (cmd[++count])
	{
		if (!skip && (!ft_strncmp(cmd[count], "-n", 2)
					|| !ft_strncmp(cmd[count], "\"-n\"", 3)))
			continue;
		skip = 1;
		write(STDOUT_FILENO, cmd[count], ft_strlen(cmd[count]));
		if (cmd[count + 1])
			write(STDOUT_FILENO, " ", 1);
	}
	if (cmd[0] && (ft_strncmp(cmd[0], "-n", 2) && ft_strncmp(cmd[0], "\"-n\"",
					3)))
		write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
	return (0);
}
