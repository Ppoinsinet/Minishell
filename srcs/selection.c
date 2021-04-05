/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:53:47 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 02:20:48 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					highlight_selection(int color)
{
	int				count;

	count = 0;
	clear_buffer();
	print_intro();
	while (ft_isprint(g_shell.input[count]))
	{
		if ((count <= g_shell.selection[0] && count >= g_shell.selection[1])
				|| (count >= g_shell.selection[0]
					&& count <= g_shell.selection[1]))
		{
			tputs(tparm(tgetstr("AF", NULL), color), 1, myputchar);
			tputs(tgetstr("us", NULL), 1, myputchar);
		}
		else
			tputs(tgetstr("me", NULL), 1, myputchar);
		write(1, &g_shell.input[count], 1);
		count++;
	}
	g_shell.cursor = (int)ft_strlen(g_shell.input);
	g_shell.lignes = (min_size() + g_shell.cursor) / g_shell.cols;
	tputs(tgetstr("me", NULL), 1, myputchar);
	return (0);
}

int					reset_highlight(int cursor_pos)
{
	clear_buffer();
	print_input();
	place_cursor(cursor_pos);
	g_shell.selection[0] = -1;
	g_shell.selection[1] = -1;
	tputs(tgetstr("ve", NULL), 1, myputchar);
	tputs(tgetstr("me", NULL), 1, myputchar);
	return (0);
}

int					selection_two(char entry[10])
{
	if (*((long *)entry) == 24)
		return (reset_highlight(g_shell.indexinput > (int)ft_strlen(
						g_shell.input) ? ft_strlen(g_shell.input)
					: g_shell.indexinput) + 1);
	else if (entry[0] == 'c')
	{
		free(g_shell.copy ? g_shell.copy : NULL);
		g_shell.copy = ft_strndup(&g_shell.input[g_shell.selection[0]
				< g_shell.selection[1] ? g_shell.selection[0]
				: g_shell.selection[1]], ft_abs(g_shell.selection[1]
					- g_shell.selection[0]) + 1);
		return (reset_highlight(g_shell.indexinput > (int)ft_strlen(
						g_shell.input) ? ft_strlen(g_shell.input) :
					g_shell.indexinput) + 1);
	}
	else if (entry[0] == 'd')
	{
		g_shell.input = ft_strremove(g_shell.input, g_shell.selection[0] <
				g_shell.selection[1] ? g_shell.selection[0] :
				g_shell.selection[1], ft_abs(g_shell.selection[1] -
					g_shell.selection[0]) + 1);
		return (reset_highlight(g_shell.selection[0] < g_shell.selection[1]
					? g_shell.selection[0] : g_shell.selection[1]) + 1);
	}
	return (0);
}

int					check_ctrl_selection(long *entry)
{
	if (*entry == CTRLRIGHT)
		index_next_word();
	else if (*entry == CTRLLEFT)
		index_previous_word();
	else
		return (1);
	g_shell.selection[1] = g_shell.indexinput;
	return (0);
}

int					selection(int index)
{
	char			entry[10];

	g_shell.selection[0] = index;
	g_shell.selection[1] = index;
	highlight_selection(COLOR_HIGHLIGHT);
	tputs(tgetstr("vi", NULL), 1, myputchar);
	while (ft_memset(entry, 0, 10 * sizeof(char)) && read(0, &entry, 10))
		if (*((long *)entry) == RIGHTARROW || *((long *)entry) == LEFTARROW)
		{
			if (*((long *)entry) == RIGHTARROW)
				g_shell.selection[1] = g_shell.selection[1] >= (int)ft_strlen(
						g_shell.input) - 1 ? (int)ft_strlen(g_shell.input) - 1 :
					g_shell.selection[1] + 1;
			else if (*((long *)entry) == LEFTARROW)
				g_shell.selection[1] = g_shell.selection[1] > 0 ?
					g_shell.selection[1] - 1 : 0;
			highlight_selection(COLOR_HIGHLIGHT);
			g_shell.lignes = (min_size() + (int)ft_strlen(g_shell.input))
				/ g_shell.cols;
		}
		else if (!check_ctrl_selection(((long *)entry)))
			highlight_selection(COLOR_HIGHLIGHT);
		else if (selection_two(entry))
			break ;
	return (0);
}
