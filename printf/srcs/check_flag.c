/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:17:10 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/12/01 14:20:33 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/strings.h"
#include "../include/ft_printf.h"

int		is_in_flags(char *flags, char c)
{
	flags++;
	while (*flags == '-' || *flags == '0'
			|| *flags == '+'
			|| *flags == ' '
			|| *flags == '#')
	{
		if (*flags == c)
			return (1);
		flags++;
	}
	return (0);
}

int		precision(char *flag)
{
	int count;

	count = 1;
	while (flag[count] == '-' || flag[count] == '0'
			|| flag[count] == '+'
			|| flag[count] == ' '
			|| flag[count] == '#')
		count++;
	while (flag[count] >= '0' && flag[count] <= '9')
		count++;
	if (flag[count] == '.')
	{
		count++;
		return (ft_atoi(&flag[count]));
	}
	return (-1);
}

int		star_in_prec(char *flag)
{
	int count;

	count = 1;
	while (flag[count] && (flag[count] == '-' || flag[count] == '0'
			|| flag[count] == '+'
			|| flag[count] == ' '
			|| flag[count] == '#'))
	{
		count++;
	}
	while (flag[count] >= '0' && flag[count] <= '9')
		count++;
	if (flag[count] == '.')
	{
		while (flag[count] >= '0' && flag[count] <= '9')
			count++;
		while (flag[count] && flag[count] != '*')
			count++;
		if (flag[count] == '*')
		{
			return (count);
		}
	}
	return (0);
}

int		star_in_field(char *flag)
{
	int count;

	count = 1;
	while (flag[count] && (flag[count] == '-' || flag[count] == '0'
			|| flag[count] == '+'
			|| flag[count] == ' '
			|| flag[count] == '#'))
	{
		count++;
	}
	while (flag[count] >= '0' && flag[count] <= '9')
		count++;
	if (flag[count] == '*')
		return (count);
	return (0);
}

int		min_field(char *flag)
{
	int count;

	count = 1;
	while (flag[count] && (flag[count] == '-' || flag[count] == '0'
			|| flag[count] == '+'
			|| flag[count] == ' '
			|| flag[count] == '#'))
	{
		count++;
	}
	return (ft_atoi(&flag[count]));
}
