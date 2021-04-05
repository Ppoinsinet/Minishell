/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:34 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/03/24 03:23:54 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char *s1, char *s2)
{
	int		taille;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	taille = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = malloc((taille * sizeof(char)) + 1)))
		return (NULL);
	ft_strlcpy(result, (char *)s1, taille + 1);
	ft_strlcpy(&result[ft_strlen(s1)], (char *)s2, taille + 1);
	return (result);
}

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	int		taille;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	taille = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = malloc((taille * sizeof(char)) + 1)))
		return (NULL);
	ft_strlcpy(result, (char *)s1, taille + 1);
	ft_strlcpy(&result[ft_strlen(s1)], (char *)s2, taille + 1);
	if (s1)
		free(s1);
	return (result);
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	int		taille;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	taille = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = malloc((taille * sizeof(char)) + 1)))
		return (NULL);
	ft_strlcpy(result, (char *)s1, taille + 1);
	ft_strlcpy(&result[ft_strlen(s1)], (char *)s2, taille + 1);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (result);
}

char		*ft_strjoin_free_two(char *s1, char *s2)
{
	int		taille;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	taille = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = malloc((taille * sizeof(char)) + 1)))
		return (NULL);
	ft_strlcpy(result, (char *)s1, taille + 1);
	ft_strlcpy(&result[ft_strlen(s1)], (char *)s2, taille + 1);
	if (s2)
		free(s2);
	return (result);
}
