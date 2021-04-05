/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:11:41 by ppoinsin          #+#    #+#             */
/*   Updated: 2020/11/19 17:40:26 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmpchar(char c, char *set)
{
	int		count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		taillestr;
	char	*add;
	char	*result;
	int		count;

	taillestr = ft_strlen((char *)s1);
	add = NULL;
	count = -1;
	if (!s1)
		return (NULL);
	while (ft_cmpchar(s1[++count], (char *)set))
		taillestr--;
	if (!s1[count])
		return (ft_strdup(""));
	add = (char *)&s1[count];
	count = ft_strlen(s1);
	while (ft_cmpchar(s1[--count], (char *)set))
		taillestr--;
	if (!(result = malloc(sizeof(char) * (taillestr + 1))))
		return (NULL);
	ft_memcpy(result, add, taillestr);
	result[taillestr] = 0;
	return (result);
}
