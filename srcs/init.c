/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:53:47 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 21:57:46 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					init_shell(void)
{
	g_shell.indexcmd = 0;
	g_shell.cursor = 0;
	g_shell.history = NULL;
	g_shell.input = NULL;
	g_shell.env = NULL;
	g_shell.size_env = 0;
	g_shell.selection[0] = -1;
	g_shell.selection[1] = -1;
	g_shell.exit_status = 0;
	g_shell.number_of_pipes = -1;
	init_pipe(&g_shell.stdin);
	init_pipe(&g_shell.stdout);
	return (0);
}
