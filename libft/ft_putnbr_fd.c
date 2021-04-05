/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:00:01 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/18 14:18:28 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int a)
{
	if (a < 0)
	{
		return (-a);
	}
	return (a);
}

static int	find_result(long count, int nb)
{
	if (count <= 100000000)
	{
		return (ft_abs(nb / count - (nb / (count * 10) * 10)));
	}
	return (ft_abs(nb / count));
}

void		ft_putnbr_fd(int nb, int fd)
{
	long	count;
	int		result;

	count = 10000000000;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	while ((count /= 10) >= 1)
	{
		if (ft_abs(nb) / count >= 1 || ft_abs(nb) / count <= -1)
		{
			result = find_result(count, nb);
			ft_putchar_fd(result + 48, fd);
		}
		else if (nb == 0)
		{
			ft_putchar_fd(48, fd);
			break ;
		}
	}
}
