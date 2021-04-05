/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:53:47 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:29:16 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell				g_shell;

int					input_choice(char entry[10])
{
	if ((ft_isprint(entry[0]) || entry[0] == 127)
			&& !entry[1])
		print_terminal(entry);
	else if (check_arrow((long *)entry, 0) == 1)
		refresh_cmd(&g_shell.input);
	else if (!check_ctrl((long *)entry))
		;
	else if (*((long *)entry) == CTRLX && ft_strlen(g_shell.input))
		selection(g_shell.indexinput < (int)ft_strlen(g_shell.input) ?
				g_shell.indexinput : (int)ft_strlen(g_shell.input) - 1);
	else if (*((long *)entry) == CTRLP && g_shell.copy)
	{
		g_shell.input = ft_strinsert(g_shell.input, g_shell.copy,
				g_shell.indexinput);
		print_input();
		place_cursor(g_shell.indexinput + ft_strlen(g_shell.copy));
	}
	else
		check_escape((long *)entry);
	return (0);
}

int					read_input(void)
{
	int				rd;
	char			entry[10];
	struct winsize	test;

	ft_memset(entry, (rd = 0), sizeof(entry));
	init_pipe(&g_shell.stdout);
	init_pipe(&g_shell.stdin);
	ioctl(0, TIOCGWINSZ, &test);
	g_shell.cols = test.ws_col;
	g_shell.lignes = (min_size()) / g_shell.cols;
	while ((rd += read(0, &entry, 10)) && !ft_strchr(entry, '\n'))
	{
		ioctl(0, TIOCGWINSZ, &test);
		g_shell.cols = test.ws_col;
		input_choice(entry);
		ft_memset(entry, 0, 10 * sizeof(char));
	}
	place_cursor(ft_strlen(g_shell.input));
	write(1, "\n", 1);
	g_shell.input = ft_strjoin_gnl(g_shell.input, "\0");
	if (has_real_char(g_shell.input))
		ft_lstadd_front(&g_shell.history, ft_lstnew(ft_strdup(g_shell.input)));
	return (0);
}

int					execute_cmd(void)
{
	int				count;

	count = -1;
	if (check_input())
	{
		free(g_shell.input);
		return (1);
	}
	g_shell.cmds = ft_shell_split(g_shell.input, ';');
	while (g_shell.cmds[++count] && has_real_char(g_shell.input))
	{
		init_pipe(&g_shell.stdin);
		init_pipe(&g_shell.stdout);
		manage_pipe(g_shell.cmds[count]);
	}
	free_split(&g_shell.cmds);
	free(g_shell.input);
	g_shell.input = NULL;
	return (0);
}

void				boucle(int count)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGWINCH, sigresize_handler);
	while ((count = -1))
	{
		g_shell.indexinput = 0;
		g_shell.cursor = 0;
		g_shell.lignes = 0;
		g_shell.input = NULL;
		g_shell.indexcmd = -1;
		print_intro();
		g_shell.lignes = 0;
		tputs(tgetstr("sc", NULL), 1, myputchar);
		read_input();
		if (execute_cmd() == 1)
			continue;
		wait(NULL);
	}
}

int					main(int ac, char **av)
{
	char			*term;

	if (ac == 2)
	{
		g_shell.input = ft_strdup(av[1]);
		execute_cmd();
		return (0);
	}
	init_shell();
	if (!(term = getenv("TERM")))
		term = "xterm-256color";
	if (tgetent(NULL, term) == -1)
		return (ft_printf("Shell42: Could not load termcap\n"));
	increment_shlvl();
	set_terminal();
	boucle(0);
	return (0);
}
