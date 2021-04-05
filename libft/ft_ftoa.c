/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:33:37 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/12/01 16:11:12 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					size_min(long double n)
{
	int				count;
	long double		num;
	int				taille;

	count = 0;
	taille = 0;
	num = (n < 0) ? -(n) : n;
	while (num / ft_fpow(10, count++) >= 1)
		taille++;
	if ((int)num == 0)
		taille++;
	return (taille);
}

long double			arrondis(long double n, int prec)
{
	if ((n - (int)n) != 0.5 && n - (int)n != -0.5)
	{
		return (n > 0 ? 5 * ft_fpow(10, -prec - 1) : -5 *
				ft_fpow(10, -prec - 1));
	}
	if (!prec && (int)n % 2 != 0)
		return (n > 0 ? 0.5 : -0.5);
	return (0);
}

int					gives_prec(long double n, int prec)
{
	int				find;

	if (prec < 0)
		find = 0;
	else
		find = 1;
	if (!find && n != 0)
		prec = 6;
	else if (!find && !n)
		prec = 6;
	return (prec);
}

char				*float_error(long double n, int *prec)
{
	if (n == INFINITY)
		return (ft_strdup("inf"));
	if (n == -INFINITY)
		return (ft_strdup("-inf"));
	if (n != n)
		return (ft_strdup("nan"));
	*prec = gives_prec(n, *prec);
	return (NULL);
}

char				*ft_ftoa(long double n, int prec)
{
	int				taille;
	int				count;
	char			*result;
	long double		num;
	char			*tmp;

	if ((result = float_error(n, &prec)))
		return (result);
	num = (n < 0) ? -(n + arrondis(n, prec)) : n + arrondis(n, prec);
	taille = (prec > 0) ? size_min(n) + 1 + prec + 1 : size_min(n) + 1 + prec;
	taille += (n < 0) ? 1 : 0;
	if (!(result = ft_calloc(taille, 1)))
		return (NULL);
	tmp = result;
	result[0] = (n < 0) ? '-' : '0';
	count = -1;
	result += (n < 0) ? 1 : 0;
	while (++count < size_min(n) + prec)
	{
		if (prec >= 1 && count == size_min(n))
			result++[count] = '.';
		result[count] = (unsigned char)((long)(num *
					(ft_fpow(10, count - size_min(n) + 1))) % 10) + 48;
	}
	return (tmp);
}
