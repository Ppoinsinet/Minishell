/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 23:53:08 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				sigquit_handler(int a)
{
	a = 0;
	if (g_shell.selection[0] != -1)
		return ;
	if (g_shell.indexinput)
		delete_char();
}

void				sigint_handler(int a)
{
	a = 0;
	if (g_shell.selection[0] != -1)
		return ;
	printf("^C\n");
	print_intro();
	free(g_shell.input);
	g_shell.input = NULL;
	g_shell.indexinput = 0;
	g_shell.lignes = (min_size()) / g_shell.cols;
}

void				sigresize_handler(int a)
{
	struct winsize	tmp;

	ioctl(0, TIOCGWINSZ, &tmp);
	if (g_shell.cols == tmp.ws_col)
		return ;
	g_shell.cols = tmp.ws_col;
	a = 0;
	g_shell.lignes = (min_size() + g_shell.cursor) / g_shell.cols;
	if (g_shell.selection[0] == -1)
		print_input();
	else
		highlight_selection(g_shell.indexinput);
	place_cursor(g_shell.indexinput);
}
