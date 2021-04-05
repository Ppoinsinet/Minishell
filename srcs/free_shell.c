/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:53:47 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 22:24:10 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					free_shell(void)
{
	free_split(&g_shell.cmds);
	ft_lstclear(&g_shell.history, free);
	g_shell.history = NULL;
	free_split(&g_shell.env);
	if (g_shell.copy)
		free(g_shell.copy);
	g_shell.copy = NULL;
	if (g_shell.input)
		free(g_shell.input);
	g_shell.input = NULL;
	if (g_shell.pipes)
		free(g_shell.pipes);
	g_shell.pipes = NULL;
	return (0);
}
