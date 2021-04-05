/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:10:24 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/29 01:00:34 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__int128_t		ft_pow(int n, int power)
{
	__int128_t	result;

	if (!power)
		return (1);
	else if (power < 0)
		return (0);
	result = 1;
	while (power--)
	{
		result *= n;
	}
	return (result);
}

char			*ft_itoa(__int128_t n)
{
	int			taille;
	int			count;
	char		*result;
	__int128_t	num;

	count = 0;
	taille = 1;
	num = (n < 0) ? -(n) : n;
	while (num / ft_pow(10, count++) >= 1)
		taille++;
	if (n <= 0)
		taille++;
	if (!(result = malloc(taille * sizeof(char))))
		return (NULL);
	result[0] = (n == 0) ? '0' : '-';
	count = (n < 0) ? 0 : -1;
	while (++count < taille - 1)
		result[count] = (num / (ft_pow(10, taille - 2 - count)) % 10) + 48;
	result[taille - 1] = 0;
	return (result);
}
