/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:36:46 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:58:47 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				clear_buffer(void)
{
	struct winsize	tmp_;
	int				tmp;

	tputs(tgetstr("me", NULL), 1, myputchar);
	ioctl(0, TIOCGWINSZ, &tmp_);
	g_shell.cols = tmp_.ws_col;
	tmp = (min_size() + g_shell.cursor) / g_shell.cols;
	while (tmp--)
		tputs(tgetstr("sr", NULL), 1, myputchar);
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, myputchar);
	tputs(tgetstr("cd", NULL), 1, myputchar);
	g_shell.cursor = 0;
	g_shell.lignes = (min_size()) / g_shell.cols;
}

void				refresh_cmd(char **input)
{
	if (!g_shell.history)
		return ;
	if (g_shell.indexcmd >= 0)
	{
		free(*input);
		*input = ft_strdup(get_n_lst(g_shell.history,
					g_shell.indexcmd)->content);
	}
	else
	{
		g_shell.indexinput = ft_strlen(g_shell.input);
		free(*input);
		*input = ft_strdup("");
	}
	print_input();
	place_cursor((int)ft_strlen(g_shell.input));
}

int					print_input(void)
{
	clear_buffer();
	g_shell.lignes = 0;
	print_intro();
	g_shell.lignes = (min_size()) / g_shell.cols;
	if (g_shell.input)
	{
		write(1, g_shell.input, ft_strlen(g_shell.input));
		write(1, " ", 1);
		g_shell.cursor = ft_strlen(g_shell.input);
		g_shell.lignes = (min_size() + (int)ft_strlen(g_shell.input))
			/ g_shell.cols;
	}
	else
	{
		g_shell.cursor = 0;
		g_shell.lignes = (min_size()) / g_shell.cols;
	}
	return (0);
}

int					print_terminal(char *entry)
{
	if (entry[0] != 127)
	{
		g_shell.input = ft_strinsert_free(g_shell.input, ft_strdup(entry),
				g_shell.indexinput);
		print_input();
		place_cursor(++g_shell.indexinput);
		return (0);
	}
	if (g_shell.indexinput <= 0)
		return (0);
	delete_char();
	return (0);
}

int					size_until(char *str, char c)
{
	int				count;

	count = 0;
	while (str[count] && str[count] != c)
	{
		count++;
	}
	return (count);
}
