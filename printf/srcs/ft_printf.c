/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 05:32:56 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/04/05 17:11:49 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/strings.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int					len_flags(char *s)
{
	int				count;

	count = 1;
	while (s[count] && (s[count] == ' ' || s[count] == '#' || s[count] == '+'
				|| s[count] == '-' || s[count] == '0'))
		count++;
	while (s[count] && (ft_isnum(s[count]) || s[count] == '*'
				|| s[count] == '-'))
		count++;
	if (s[count] == '.')
		count++;
	while (s[count] && (ft_isnum(s[count]) || s[count] == '*'
				|| s[count] == '-'))
		count++;
	if (s[count] && (!ft_strncmp(&s[count], "ll", 2)
				|| !ft_strncmp(&s[count], "hh", 2)))
		count += 2;
	if (s[count] && (!ft_strncmp(&s[count], "l", 1)
				|| !ft_strncmp(&s[count], "h", 1)))
		count++;
	if (s[count])
		return (count + 1);
	return (count);
}

int					write_free(char *str, int null)
{
	int				count;
	int				len;

	len = ft_strlen(str);
	count = 0;
	if (!str)
		return (-1);
	if (null == 0)
		ft_putchar_fd(0, STDERR_FILENO);
	while (str[count])
	{
		ft_putchar_fd(str[count], STDERR_FILENO);
		count++;
	}
	if (count == null && count)
		ft_putchar_fd(0, STDERR_FILENO);
	free(str);
	return (len);
}

int					ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int					ft_printf(const char *str, ...)
{
	va_list			arg;
	int				len;

	len = 0;
	if (!str || (ft_strlen(str) == 1 && *str == '%'))
		return (0);
	va_start(arg, (char *)str);
	while (str && *str)
	{
		if (*str != '%')
		{
			write(STDERR_FILENO, (char *)str, 1);
			len++;
		}
		else if (len_flags((char *)str) != 1)
			treat_flag((char **)&str, arg, &len);
		if (str)
			str++;
	}
	va_end(arg);
	return (len);
}
