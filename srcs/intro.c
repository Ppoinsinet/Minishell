/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 21:23:21 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*give_cwd(void)
{
	char			*cwd;

	if (!(cwd = malloc(sizeof(char) * 2048)))
		return (NULL);
	getcwd(cwd, 2048);
	return (cwd);
}

int					size_intro(void)
{
	char			*tmp;
	char			*tmp2;
	int				size;

	tmp = get_env_var("PWD");
	if (tmp && *tmp)
	{
		tmp = ft_strreplace(tmp, get_env_var_two("HOME"), "~");
		if ((tmp2 = ft_strchr(tmp, '=')))
			size = (int)ft_strlen(tmp2 + 1);
		else
			size = 0;
		free(tmp);
		return (size);
	}
	return (0);
}

void				print_intro(void)
{
	char			*buff;
	struct winsize	tmp;

	ioctl(0, TIOCGWINSZ, &tmp);
	g_shell.cols = tmp.ws_col;
	buff = give_cwd();
	add_env_var(ft_strjoin_gnl(ft_strdup("PWD="), buff));
	tputs(tgetstr("bl", NULL), 1, &myputchar);
	tputs(tparm(tgetstr("AF", NULL), COLOR_RED), 1, &myputchar);
	write(1, "Shell42 ", 8);
	tputs(tgetstr("me", NULL), 1, &myputchar);
	write(1, "- ", 2);
	tputs(tparm(tgetstr("AF", NULL), COLOR_GREEN), 1, &myputchar);
	buff = ft_strreplace(buff, get_env_var_two("HOME"), "~");
	write(1, buff, ft_strlen(buff));
	tputs(tgetstr("me", NULL), 1, &myputchar);
	write(1, ": ", 2);
	free(buff);
}
