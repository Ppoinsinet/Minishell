/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:18:30 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/02 21:14:19 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*get_n_lst(t_list *lst, int n)
{
	int				count;

	count = 0;
	while (count < n && lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (lst);
}
