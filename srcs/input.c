/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:42 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 03:08:59 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					has_real_char(char *str)
{
	while (*str)
	{
		if (ft_isprint(*str) && *str != 32)
			return (1);
		str++;
	}
	return (0);
}

int					check_escape(long *entry)
{
	if (*entry == 4)
	{
		printf("exit\n");
		free_shell();
		exit(EXIT_SUCCESS);
	}
	else if (*entry == 22)
		return (1);
	return (0);
}

int					myputchar(int c)
{
	write(1, &c, 1);
	return (0);
}

int					check_ctrl(long *entry)
{
	if (*entry == CTRLRIGHT)
		index_next_word();
	else if (*entry == CTRLLEFT)
		index_previous_word();
	else if (*entry == END_KEY)
	{
		print_input();
		place_cursor(ft_strlen(g_shell.input));
	}
	else if (*entry == HOME_KEY)
	{
		if (g_shell.indexinput > 0)
		{
			print_input();
			place_cursor(0);
		}
	}
	else
		return (1);
	return (0);
}
