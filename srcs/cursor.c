/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:36:46 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 23:48:40 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		index_next_word(void)
{
	char	*tmp;

	if (!g_shell.input)
		return ;
	tmp = next_word(&g_shell.input[g_shell.indexinput]);
	if (!tmp)
		return ;
	g_shell.indexinput = (int)(tmp - g_shell.input);
	place_cursor((int)(tmp - g_shell.input));
}

void		index_previous_word(void)
{
	char	*tmp;

	if (!g_shell.input)
		return ;
	tmp = previous_word(g_shell.input, g_shell.indexinput - 1);
	if (!tmp)
		return ;
	g_shell.indexinput = (int)(tmp - g_shell.input);
	place_cursor((int)(tmp - g_shell.input));
}

void		place_cursor(int index)
{
	int				tmp;
	struct winsize	tmp_;

	ioctl(0, TIOCGWINSZ, &tmp_);
	g_shell.cols = tmp_.ws_col;
	g_shell.lignes = (min_size() + g_shell.cursor) / g_shell.cols;
	tmp = g_shell.lignes;
	while (tmp--)
		tputs(tgetstr("sr", NULL), 1, myputchar);
	tmp = (min_size() + index) / g_shell.cols;
	while (tmp--)
		tputs(tgetstr("sf", NULL), 1, myputchar);
	tputs(tgoto(tgetstr("ch", NULL), 0, (min_size() + index) % g_shell.cols),
			1, myputchar);
	g_shell.cursor = index;
	g_shell.indexinput = index;
}
