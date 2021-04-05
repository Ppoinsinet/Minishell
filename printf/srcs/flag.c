/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:39:06 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:13:33 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/strings.h"

int					skip_flag(char **flag, int *len)
{
	*len += 0;
	if (!is_correct(*(*flag + len_flags(*flag) - 1))
			&& ft_isalpha(*(*flag + len_flags(*flag) - 1)))
	{
		ft_putchar_fd(1, STDERR_FILENO);
		*flag += len_flags(*flag) - 1;
		return (1);
	}
	else if (!is_correct(*(*flag + len_flags(*flag) - 1))
			&& !ft_isalpha(*(*flag + len_flags(*flag - 1))))
	{
		*flag += len_flags(*flag) - 1;
		return (1);
	}
	return (0);
}

void				treat_flag(char **str, va_list arg, int *len)
{
	char			*flag;
	char			*tmp;
	int				null;

	null = -1;
	flag = ft_strndup((char *)*str, len_flags((char *)*str));
	treat_stars(&flag, arg);
	if (!is_correct(flag[len_flags(flag) - 1]))
		tmp = appendchar(flag[len_flags(flag) - 1], 1);
	else
	{
		tmp = ft_args(flag, arg, *len);
		if (!ft_strchr(flag, 'n'))
			treat_prec(&tmp, flag);
	}
	treat_hex(flag, &tmp);
	if (!ft_strchr(flag, 'u') && !ft_strchr(flag, 'n'))
		prefix(flag, &tmp);
	null = (!ft_strchr(flag, 'n')) ? treat_field(&tmp, flag) : -1;
	*len += (null < 0) ? ft_strlen(tmp) : ft_strlen(tmp) + 1;
	*str += len_flags((char *)*str) - 1;
	write_free(tmp, null);
	free(flag);
}

char				*is_in_arg(char *flag, char c)
{
	int				count;
	int				size;

	size = len_flags(flag);
	count = 0;
	while (count < size)
	{
		if (flag[count] == c)
			return (&flag[count]);
		count++;
	}
	return (NULL);
}

int					is_hex(char *flags)
{
	return (ft_strchr(flags, 'x') || ft_strchr(flags, 'X'));
}

int					is_decimal(char *flags)
{
	return (ft_strchr(flags, 'd') || ft_strchr(flags, 'i')
			|| ft_strchr(flags, 'u'));
}
