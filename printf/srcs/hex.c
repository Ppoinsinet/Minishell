/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:55:19 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/12/01 16:24:05 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/strings.h"
#include "../include/ft_printf.h"

static void		ft_putnbr_base(__int128_t nbr, char **str, int index
		, char *base)
{
	int			taillebase;

	taillebase = ft_strlen(base);
	(*str)[index] = base[nbr % taillebase];
	if (index > 0)
		ft_putnbr_base(nbr / taillebase, str, index - 1, base);
}

char			*puthex(__int128_t nbr, char *base)
{
	int			taillebase;
	int			size;
	char		*result;

	nbr = (nbr < 0) ? -nbr : nbr;
	size = 0;
	taillebase = ft_strlen(base);
	while (nbr / ft_pow(taillebase, size) >= 1)
		size++;
	if (!nbr)
		size++;
	if (!(result = malloc(size * sizeof(char) + 1)))
		return (NULL);
	result[0] = '0';
	ft_putnbr_base(nbr, &result, size - 1, base);
	result[size] = 0;
	return (result);
}

char			*treat_hex(char *flag, char **txt)
{
	if (!flag || !txt || !*txt)
		return (NULL);
	if ((is_hex(flag) && is_in_flags(flag, '#')) || ft_strchr(flag, 'p'))
	{
		if (ft_strchr(flag, 'p') || !(ft_strlen(*txt) == 1 && **txt == '0'))
			*txt = (ft_strchr(flag, 'X')) ? appendstart(*txt, ft_strdup("0x"))
				: appendstart(*txt, ft_strdup("0x"));
	}
	else if (ft_strchr(flag, 'o') && ft_strchr(flag, '#') && **txt != '0'
			&& **txt)
		*txt = appendstart(*txt, ft_strdup("0"));
	return (*txt);
}
