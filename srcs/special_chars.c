/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:17:20 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:55:20 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				gives_special_char(char c, char *num)
{
	char			space;

	space = 0;
	if (c == (*num = 'n'))
		space = '\n';
	else if (c == (*num = 't'))
		space = '\t';
	else if (c == (*num = 'v'))
		space = '\v';
	else if (c == (*num = 'b'))
		space = '\b';
	else if (c == (*num = 'f'))
		space = '\f';
	return (space);
}

static char			*delete_shell_chars(char *input)
{
	char			*tmp;
	char			*tmp_;
	int				count;

	if (!(tmp = ft_calloc(sizeof(char), ft_strlen(input))))
		return (input);
	count = -1;
	while (input[++count])
		if (input[count] == '\'' || input[count] == '\"')
		{
			tmp[count] = 1;
			if (!(tmp_ = ft_strchr(&input[count + 1], input[count])))
				break ;
			count = (int)(tmp_ - input) - 1;
		}
	count = ft_strlen(input) - 1;
	while (count >= 0)
	{
		if (tmp[count] == 1)
			input = ft_strremove(input, count, 1);
		count--;
	}
	free(tmp);
	return (input);
}

char				*input_chars_two(char *input)
{
	int				count;

	count = 0;
	while (input && input[count])
	{
		if (input[count] == '\\' && !is_between_guill(input, &input[count]))
			input = ft_strremove(input, count, 1);
		else if (!is_between_guill(input, &input[count]) && (input[count] == '>'
					|| input[count] == '<' || (input[count] == '$'
						&& gives_var_size(&input[count]) == 1)))
			input = ft_strremove(input, count--, 1);
		count++;
	}
	if (input)
	{
		input = delete_shell_chars(input);
	}
	return (input);
}

char				*input_chars(char *input)
{
	int				count;
	char			space;
	char			num;

	count = 0;
	while (input && input[count])
	{
		if (input[count] == '\\')
		{
			space = gives_special_char(input[count + 1], &num);
			if (space && is_contained_between(input, &input[count], "$\'",
						"\'") > -1 && is_between_guill(input, &input[count])
					!= '\"')
			{
				input = ft_strremove(input, count, 1);
				input[count] = space;
			}
			else if (space && !is_between_guill(input, &input[count]))
			{
				input = ft_strremove(input, count, 1);
			}
		}
		count++;
	}
	return ((input = input_chars_two(input)));
}
