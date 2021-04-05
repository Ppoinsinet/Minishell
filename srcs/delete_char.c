/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 01:36:46 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 23:38:06 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			delete_char(void)
{
	g_shell.input = ft_strremove(g_shell.input, g_shell.indexinput - 1, 1);
	print_input();
	place_cursor(--g_shell.indexinput);
	return (0);
}
