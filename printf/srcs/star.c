/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:47:21 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:37:07 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/strings.h"
#include "../include/ft_printf.h"
#include "../include/libft.h"

int					treat_stars(char **flag, va_list arg)
{
	char			*tmp;
	int				star;

	if ((star = star_in_field(*flag)))
	{
		tmp = ft_itoa((int)va_arg(arg, int));
		*flag = ft_strremove(*flag, star, 1);
		*flag = ft_strinsert_free(*flag, tmp, star);
	}
	if ((star = star_in_prec(*flag)))
	{
		tmp = ft_itoa((int)va_arg(arg, int));
		*flag = ft_strremove(*flag, star, 1);
		*flag = ft_strinsert_free(*flag, tmp, star);
	}
	return (0);
}
