/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:06:08 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 19:26:45 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					find_dir(char *path, char *file)
{
	DIR				*directory;
	struct dirent	*tmp;

	if (!(directory = opendir(path)))
		return (-1);
	while ((tmp = readdir(directory)))
	{
		if (!strcmp(tmp->d_name, file))
		{
			closedir(directory);
			return (0);
		}
	}
	closedir(directory);
	return (-1);
}

int					ft_cd_previous(char **cmd)
{
	char			*tmp;

	free(cmd[1]);
	if ((tmp = ft_strchr(get_env_var("OLDPWD"), '=')))
		cmd[1] = ft_strdup(tmp + 1);
	else
	{
		cmd[1] = NULL;
		return (ft_printf("cd: directory not found\n"));
	}
	if (chdir(cmd[1]) == -1)
		return (ft_printf("cd: %s\n", strerror(errno)));
	add_env_var(ft_strjoin("OLDPWD=", ft_strchr(get_env_var_two("PWD"), '=')
				+ 1));
	cmd[1] = ft_strreplace(cmd[1], get_env_var_two("HOME"), "~");
	return (0);
}

int					ft_cd(char **cmd)
{
	char			*tmp;

	if (!cmd[1])
	{
		if ((tmp = get_env_var_two("HOME")))
			if ((tmp = ft_strchr(tmp, '=')))
				tmp = tmp + 1;
		return (chdir(get_env_var_two("HOME")) == -1 ? ft_printf("cd: %s\n",
					strerror(errno)) : 0);
	}
	else if (cmd[2])
		return (ft_printf("cd: syntax error\n"));
	else if (!ft_strcmp(cmd[1], "-"))
	{
		if (ft_cd_previous(cmd))
			return (1);
		return (printf("%s\n", cmd[1]));
	}
	else if (!ft_strcmp(cmd[1], "~"))
	{
		free(cmd[1]);
		cmd[1] = get_env_var("HOME");
	}
	if (chdir(cmd[1]) == -1)
		return (ft_printf("cd: %s\n", strerror(errno)));
	return (add_env_var(ft_strjoin("OLDPWD=", ft_strchr(get_env_var_two("PWD"),
						'=') + 1)));
}
