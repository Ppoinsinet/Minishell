/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:15:27 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 23:39:10 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_env(void)
{
	int				count;

	if (!fork())
	{
		duplicate_pipes();
		count = 0;
		while (g_shell.env[count])
		{
			printf("%s\n", g_shell.env[count]);
			count++;
		}
		exit(EXIT_SUCCESS);
	}
	else
		wait(&g_shell.exit_status);
	return (0);
}

char				**env_remove(char **cmd, char *name)
{
	char			**res;
	char			found;
	int				size;
	int				size2;

	size = -1;
	found = 0;
	while (cmd[++size])
		if (!found && !ft_strncmp(cmd[size], name, ft_strlen(name)))
			found = 1;
	if (!found || !(res = ft_calloc(sizeof(char *), size)))
		return (NULL);
	size = -1;
	size2 = 0;
	g_shell.size_env--;
	while (cmd[++size])
		if (ft_strncmp(cmd[size], name, ft_strlen(name)))
			res[size2++] = cmd[size];
		else
			free(cmd[size]);
	return (res);
}

int					alpha_sort(char *str, char *str2)
{
	int				count;

	count = 0;
	if (!str && str2)
		return (1);
	else if (!str)
		return (0);
	while (str[count])
	{
		if (str[count] != str2[count])
			return (str[count] > str2[count] ? 1 : -1);
		count++;
	}
	return (str[count] - str2[count]);
}

int					not_in_env(char *str, char **env)
{
	while (*env)
	{
		if (*env == str)
			return (1);
		env++;
	}
	return (0);
}

char				**sort_env(char **cmd)
{
	int				count;
	int				count2;
	int				size;
	char			**res;

	size = 0;
	while (cmd[size])
		size++;
	if (!(res = ft_calloc(sizeof(char *), (size + 1))))
		return (NULL);
	res[size] = 0;
	count2 = -1;
	count = -1;
	while (++count2 < size)
	{
		count = -1;
		while (++count < size)
			if (alpha_sort(res[count2], cmd[count]) > 0
					&& !not_in_env(cmd[count], res))
				res[count2] = cmd[count];
	}
	return (res);
}
