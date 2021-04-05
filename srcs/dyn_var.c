/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:53:47 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 02:33:50 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				increment_shlvl(void)
{
	char			*tmp;
	char			*tmp_;
	int				a;

	tmp = getenv("SHLVL");
	if (*tmp)
	{
		a = ft_atoi(tmp);
		tmp_ = ft_itoa(a + 1);
		tmp = ft_strjoin_free_two("SHLVL=", tmp_);
		add_env_var(tmp);
	}
	else
	{
		tmp = ft_strdup("SHLVL=1");
		add_env_var(tmp);
	}
}

void				add_dyn_variable(char **cmd)
{
	int				count;

	count = 0;
	while (cmd[count])
		count++;
	add_env_var(ft_strjoin("_=", cmd[count - 1]));
}
