/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:33:59 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:36:16 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/strings.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

char				char_to_print(char *flag, int side)
{
	if (side == -1 && is_in_flags(flag, '0'))
	{
		if (precision(flag) < 0 || ft_strchr(flag, 's')
				|| ft_strchr(flag, 'c') || ft_strchr(flag, 'f')
				|| ft_strchr(flag + 1, '%'))
			return ('0');
	}
	return (' ');
}

char				*print_field(char *flag, char **txt, int size, int side)
{
	char			c;

	c = char_to_print(flag, side);
	if (min_field(flag) <= size)
		return (*txt);
	if (space(flag) && (ft_strchr(*txt, '-') || ft_strchr(*txt, '+')
				|| ft_strchr(*txt, ' ')) && c == '0')
		*txt = (side == -1) ?
			ft_strinsert_free(*txt, appendchar(c, min_field(flag) - size), 1) :
			appendend_char(*txt, ' ', min_field(flag) - size);
	else if ((is_hex(flag) && is_in_flags(flag, '#')) || ft_strchr(flag, 'p'))
	{
		if (side == -1 && c == '0')
			*txt = ft_strinsert_free(*txt, appendchar(c, min_field(flag) - size)
					, 2);
		else if (side == -1 && c == ' ')
			*txt = appendstart_char(*txt, c, min_field(flag) - size);
		else
			*txt = appendend_char(*txt, c, min_field(flag) - size);
	}
	else
		*txt = (side == -1) ?
			appendstart_char(*txt, c, min_field(flag) - size) :
			appendend_char(*txt, ' ', min_field(flag) - size);
	return (*txt);
}

int					treat_field(char **txt, char *flag)
{
	int				side;
	int				size;
	int				null;

	null = (ft_strchr(flag, 'c') && !**txt) ? 1 : 0;
	size = (ft_strchr(flag, 'c')) ? 1 : ft_strlen(*txt);
	side = (is_in_flags(flag, '-')) ? 1 : -1;
	print_field(flag, txt, size, side);
	if (null)
	{
		if (side == -1)
			return ((min_field(flag) - size) > 0 ? min_field(flag) - size : 0);
		else if (side == 1)
			return (0);
	}
	return (-1);
}
