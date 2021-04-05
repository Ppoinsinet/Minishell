/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 06:13:25 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/28 18:16:55 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"
#include "../include/strings.h"

char		*appendstart(char *dst, char *src)
{
	int		taille;
	char	*result;

	taille = ft_strlen(dst) + ft_strlen(src);
	if (!(result = malloc(sizeof(char) * taille + 1)))
		return (NULL);
	ft_strcpy(result, src);
	ft_strcpy(&result[ft_strlen(src)], dst);
	result[taille] = 0;
	free(dst);
	free(src);
	return (result);
}

char		*appendstart_char(char *dst, char c, int n)
{
	int		taille;
	char	*result;
	char	*src;

	if (n <= 0)
		return (dst);
	src = appendchar(c, n);
	taille = ft_strlen(dst) + ft_strlen(src);
	if (!(result = malloc(sizeof(char) * taille + 1)))
		return (NULL);
	ft_strcpy(result, src);
	ft_strcpy(&result[ft_strlen(src)], dst);
	result[taille] = 0;
	free(dst);
	free(src);
	return (result);
}

char		*appendend(char *dst, char *src)
{
	int		taille;
	char	*result;

	taille = ft_strlen(dst) + ft_strlen(src);
	if (!(result = malloc(sizeof(char) * taille + 1)))
		return (NULL);
	ft_strcpy(result, dst);
	ft_strcpy(&result[ft_strlen(dst)], src);
	result[taille] = 0;
	free(dst);
	free(src);
	return (result);
}

char		*appendend_char(char *dst, char c, int n)
{
	int		taille;
	char	*result;
	char	*src;

	if (n <= 0)
		return (dst);
	src = appendchar(c, n);
	taille = ft_strlen(dst) + ft_strlen(src);
	if (!(result = malloc(sizeof(char) * taille + 1)))
		return (NULL);
	ft_strcpy(result, dst);
	ft_strcpy(&result[ft_strlen(dst)], src);
	result[taille] = 0;
	free(dst);
	free(src);
	return (result);
}

char		*appendchar(char c, int n)
{
	char	*result;
	int		count;

	if (n <= 0)
		return (ft_strdup(""));
	if (!(result = malloc(n * sizeof(char) + 1)))
		return (NULL);
	count = 0;
	while (count < n)
	{
		result[count] = c;
		count++;
	}
	result[count] = 0;
	return (result);
}
