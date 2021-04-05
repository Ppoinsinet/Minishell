/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:10:37 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/01/28 00:04:36 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*nxt;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		nxt = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = nxt;
	}
	*lst = NULL;
}
