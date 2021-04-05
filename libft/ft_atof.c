/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:34:43 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/01/28 22:38:23 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

float		ft_atof(char *s)
{
	float	result;
	int		signe;
	char	*point;
	int		decimale;

	decimale = 0;
	point = ft_strchr(s, '.') ? ft_strchr(s, '.') : s + ft_strlen(s);
	signe = 1;
	result = 0;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			signe *= -1;
		s++;
	}
	while ((*s >= '0' && *s <= '9') || (!decimale && *s == '.'))
	{
		if (*s == '.')
			decimale++;
		else
			result += !decimale ? ft_fpow(10, (int)(point - s - 1))
				* (*s - '0') : ft_fpow(10, (int)(point - s)) * (*s - '0');
		s++;
	}
	return (signe * result);
}
