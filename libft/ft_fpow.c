/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:37:14 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/01/09 01:13:21 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

float			ft_fpow(float n, int power)
{
	float		result;

	if (!power)
		return (1);
	result = 1;
	while (power > 0 && power--)
	{
		result *= n;
	}
	while (power < 0 && power++)
	{
		result /= n;
	}
	return (result);
}
