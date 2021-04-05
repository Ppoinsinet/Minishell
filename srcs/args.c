/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 20:53:47 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/03 04:23:25 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				**treat_args(char **cmd)
{
	char			**tmp;

	tmp = cmd;
	while (*tmp)
	{
		*tmp = env_var_input(*tmp);
		*tmp = input_chars(*tmp);
		tmp++;
	}
	return (cmd);
}
