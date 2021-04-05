/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:20 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/04 19:32:26 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					size_word_pipe(char *str)
{
	int				count;

	count = 0;
	while (str[count] && ((str[count] != '>' && str[count] != '<' && str[count]
					!= '|') || (count > 0 && str[count - 1] == '\\')))
		count++;
	return (count);
}

char				*delete_pipe_arg(char *cmd, char *cursor)
{
	char			*tmp;
	int				index;
	int				len;

	if (!cmd)
		return (NULL);
	if (!cursor || !(tmp = pipe_next_word(cursor)))
		return (cmd);
	index = (cursor - cmd);
	len = size_word_pipe(tmp) + (tmp - cursor);
	if (!len)
		return (cmd);
	tmp = ft_strremove(cmd, index, len);
	return (tmp);
}

char				*delete_pipe_type(char *cmd, char *pipe)
{
	int				index;
	char			*tmp;
	int				len;

	len = ft_strlen(pipe);
	tmp = cmd;
	while (*tmp && (tmp = ft_strstr(tmp, pipe)))
	{
		index = (tmp - cmd);
		if (!index || *(tmp - 1) == '\\')
		{
			tmp++;
			break ;
		}
		cmd = delete_pipe_arg(cmd, tmp);
		tmp = &cmd[(int)ft_strlen(cmd) > index ? index : ft_strlen(cmd)];
	}
	return (cmd);
}

char				*delete_pipes(char *cmd)
{
	cmd = delete_pipe_type(cmd, "<");
	cmd = delete_pipe_type(cmd, ">>");
	cmd = delete_pipe_type(cmd, ">");
	return (cmd);
}
