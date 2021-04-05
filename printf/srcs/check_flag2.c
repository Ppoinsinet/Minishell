/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:24:21 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/12/01 14:42:44 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/strings.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

void				remove_char(char **txt, char c, int keep)
{
	int count;

	count = 0;
	while ((*txt)[count])
	{
		if ((*txt)[count] == c)
		{
			if (keep)
			{
				keep--;
			}
			else
			{
				*txt = ft_strremove(*txt, count, 1);
				count--;
			}
		}
		count++;
	}
}

int					is_correct(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
			|| c == 'x' || c == 'X' || c == '%' || c == 'o' || c == 'f'
			|| c == 'n' || c == 'l' || c == 'h')
		return (1);
	return (0);
}

char				*ft_args(char *flags, va_list argpt, int len)
{
	char			*tmp;

	if (ft_strchr(flags, 'd') || ft_strchr(flags, 'i'))
		return (ft_itoa(size_bonus(flags, argpt, 1)));
	else if (ft_strchr(flags, 'u'))
		return (ft_itoa(size_bonus(flags, argpt, 0)));
	else if (ft_strchr(flags, 's') && (tmp = va_arg(argpt, char *)))
		return (ft_strdup(tmp));
	else if (ft_strchr(flags, 'c'))
		return (appendchar(va_arg(argpt, int), 1));
	else if (ft_strchr(flags, 'p'))
		return (puthex((va_arg(argpt, unsigned long)), "0123456789abcdef"));
	else if (ft_strchr(flags, 'x'))
		return (puthex(size_bonus(flags, argpt, 0), "0123456789abcdef"));
	else if (ft_strchr(flags, 'X'))
		return (puthex(size_bonus(flags, argpt, 0), "0123456789ABCDEF"));
	else if (ft_strchr(flags + 1, '%'))
		return (appendchar('%', 1));
	else if (ft_strchr(flags, 'f'))
		return (ft_ftoa(va_arg(argpt, double), precision(flags)));
	else if (ft_strchr(flags, 'o'))
		return (puthex(size_bonus(flags, argpt, 0), "01234567"));
	else if (ft_strchr(flags, 'n'))
		*(va_arg(argpt, int *)) = len;
	return (ft_strchr(flags, 's') ? ft_strdup("(null)") : ft_strdup(""));
}

int					space(char *flg)
{
	if (ft_strchr(flg, 'i') || ft_strchr(flg, 'd') || ft_strchr(flg, 'f'))
		return (1);
	return (0);
}

char				*prefix(char *flg, char **txt)
{
	__int128_t		tmp;

	if (is_in_flags(flg, ' ') && !is_in_flags(flg, '+')
			&& (space(flg)))
	{
		if (**txt != '-')
			*txt = appendstart_char(*txt, ' ', 1);
	}
	else if (is_in_flags(flg, '+') && space(flg))
	{
		tmp = ft_atoi(*txt);
		if ((tmp >= 0 || ft_strchr(flg, 'p')) && !ft_strchr(flg, 'f'))
			*txt = appendstart_char(*txt, '+', 1);
		else if (ft_strchr(flg, 'f') && **txt != '+' && **txt != '-')
			*txt = appendstart_char(*txt, '+', 1);
	}
	return (flg);
}
