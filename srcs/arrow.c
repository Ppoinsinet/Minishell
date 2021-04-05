/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 23:47:57 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			side_arrow_two(int c)
{
	if (c < 0)
	{
		if (!((INTRO_LENGTH + size_intro() + g_shell.indexinput)
					% g_shell.cols))
		{
			g_shell.lignes--;
			tputs(tgetstr("sr", NULL), 1, myputchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, g_shell.cols), 1, myputchar);
		}
		else
			tputs(tgetstr("le", NULL), 1, myputchar);
		g_shell.indexinput--;
		g_shell.cursor--;
		return ;
	}
	if (!((INTRO_LENGTH + size_intro() + g_shell.indexinput + 1)
				% g_shell.cols))
	{
		tputs(tgetstr("sf", NULL), 1, myputchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, myputchar);
	}
	else
		tputs(tgetstr("nd", NULL), 1, myputchar);
	g_shell.indexinput++;
	g_shell.cursor++;
}

int					side_arrow(long *entry, char mode)
{
	if (*entry == LEFTARROW && g_shell.indexinput > 0)
	{
		side_arrow_two(-1);
	}
	if (*entry == RIGHTARROW && ((!mode && g_shell.indexinput <
					(int)ft_strlen(g_shell.input)) || (mode &&
					g_shell.indexinput < (int)ft_strlen(g_shell.input) - 1)))
	{
		side_arrow_two(1);
	}
	g_shell.lignes = (min_size() + g_shell.cursor) / g_shell.cols;
	return (0);
}

int					check_arrow(long *entry, char mode)
{
	if ((*entry == UPARROW || *entry == DOWNARROW) && !mode)
	{
		*entry == UPARROW ? g_shell.indexcmd++ : g_shell.indexcmd--;
		if (g_shell.indexcmd > ft_lstsize(g_shell.history) - 1)
			g_shell.indexcmd = ft_lstsize(g_shell.history) - 1;
		if (g_shell.indexcmd < -1)
			g_shell.indexcmd = -1;
	}
	else if ((*entry == LEFTARROW || *entry == RIGHTARROW))
	{
		side_arrow(entry, mode);
		return (2);
	}
	else
		return (0);
	return (1);
}

void				set_terminal(void)
{
	struct termios	change;

	tcgetattr(0, &change);
	change.c_lflag &= ~(ICANON | ECHO);
	change.c_cc[VMIN] = 1;
	change.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &change);
}
