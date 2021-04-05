/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:51:55 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 23:40:16 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

int		min_size(void)
{
	return (size_intro() + INTRO_LENGTH);
}
