/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 19:48:04 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/29 21:16:34 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/strings.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int					has_bonus(char *flags)
{
	if (ft_strchr(flags, 'l') || ft_strchr(flags, 'h'))
		return (1);
	return (0);
}

__int128_t			l_bonus(char *flags, va_list argpt, int sign, int *done)
{
	if (ft_strnstr(flags, "ll", ft_strlen(flags)))
	{
		*done = 1;
		if (sign)
			return (va_arg(argpt, long long int));
		return (va_arg(argpt, unsigned long long int));
	}
	else if (ft_strchr(flags, 'l'))
	{
		*done = 1;
		if (sign)
			return (va_arg(argpt, long int));
		return (va_arg(argpt, unsigned long int));
	}
	sign = 1;
	*done = 0;
	return (0);
}

__int128_t			size_bonus(char *flags, va_list argpt, int sign)
{
	int				done;
	__int128_t		result;

	result = l_bonus(flags, argpt, sign, &done);
	if (done)
		return (result);
	else if (ft_strnstr(flags, "hh", ft_strlen(flags)))
	{
		if (sign)
			return ((char)va_arg(argpt, int));
		return ((unsigned char)va_arg(argpt, int));
	}
	else if (ft_strchr(flags, 'h'))
	{
		if (sign)
			return ((short int)va_arg(argpt, int));
		return ((unsigned short int)va_arg(argpt, int));
	}
	if (sign)
		return (va_arg(argpt, int));
	return (va_arg(argpt, unsigned int));
}
