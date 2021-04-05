/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:36:53 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 21:22:13 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					add_new_env(char *str)
{
	char			**env;
	int				count;

	if (!(env = ft_calloc(sizeof(char *), (g_shell.size_env + 2))))
		return (1);
	env[g_shell.size_env + 1] = 0;
	count = 0;
	while (g_shell.env[count])
	{
		env[count] = g_shell.env[count];
		count++;
	}
	free(g_shell.env);
	env[count] = str;
	g_shell.size_env++;
	g_shell.env = env;
	return (0);
}

int					add_env_var(char *str)
{
	int				count;

	if (!g_shell.env)
	{
		if (!(g_shell.env = malloc(sizeof(char *) * 2)))
			return (0);
		g_shell.size_env = 1;
		g_shell.env[0] = str;
		g_shell.env[1] = NULL;
		return (0);
	}
	count = 0;
	while (g_shell.env[count])
	{
		if (!ft_strncmp(g_shell.env[count], str, size_until(str, '=')))
		{
			free(g_shell.env[count]);
			g_shell.env[count] = str;
			return (0);
		}
		count++;
	}
	add_new_env(str);
	return (0);
}

char				*get_env_var(char *name)
{
	int				count;

	count = 0;
	if (!g_shell.env)
		return (ft_strdup(""));
	while (g_shell.env[count])
	{
		if (!ft_strncmp(name, g_shell.env[count], ft_strlen(name))
				&& ft_strlen(name) >= 1)
		{
			return (ft_strdup(g_shell.env[count]));
		}
		count++;
	}
	return (ft_strdup(""));
}

char				*get_env_var_two(char *name)
{
	int				count;

	if (!g_shell.env)
		return ("");
	count = 0;
	while (g_shell.env[count])
	{
		if (!ft_strncmp(name, g_shell.env[count], ft_strlen(name)))
		{
			return (g_shell.env[count]);
		}
		count++;
	}
	return ("");
}

int					init_env_var(void)
{
	char			*line;
	int				fd;

	line = NULL;
	if ((fd = open(ENVDIR, O_RDONLY)) == -1)
		return (2);
	while (get_next_line(fd, &line))
	{
		add_env_var(ft_strdup(line));
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}
