/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:32:56 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:36:46 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/strings.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

char				**treat_prec(char **txt, char *flag)
{
	int				prec;

	prec = precision(flag);
	if (prec <= -1 || ft_strchr(flag + 1, '%'))
		return (NULL);
	if (!ft_strchr(flag, 's') && !ft_strchr(flag, 'c') && prec >= 0)
	{
		if (!ft_strncmp("0", *txt, ft_strlen(*txt))
				&& !prec && !ft_strchr(flag, 'f'))
			*txt = ft_strremove(*txt, 0, ft_strlen(*txt));
		else
		{
			if (space(flag) && ft_strchr(*txt, '-'))
				*txt = ft_strinsert_free(*txt, appendchar('0', prec
							- ft_strlen(*txt) + 1), 1);
			else
				*txt = appendstart_char(*txt, '0', prec - ft_strlen(*txt));
		}
	}
	else if (ft_strchr(flag, 's') && prec < (int)ft_strlen(*txt))
		*txt = ft_strremove(*txt, prec, ft_strlen(*txt) - prec);
	return (txt);
}
