/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:19:02 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/29 01:00:24 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__int128_t		ft_atoi(const char *str)
{
	int			signe;
	__int128_t	result;

	result = 0;
	signe = 1;
	while (*str == '\r' || *str == '\t' || *str == '\v' || *str == '\f'
			|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + *str - 48;
		if (result < 0)
			return (-1);
		str++;
	}
	return ((__int128_t)(result * signe));
}
