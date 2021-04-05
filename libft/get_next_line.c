/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinsin <ppoinsin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:54:06 by ppoinsin          #+#    #+#             */
/*   Updated: 2021/03/25 00:08:48 by ppoinsin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				moves_buff(char *buff, int cursor)
{
	if (cursor <= 0)
		return (0);
	ft_memmove(buff, &buff[cursor], BUFFER_SIZE + 1 - cursor);
	cursor = ft_strlen(buff);
	ft_memset(&buff[cursor], 0, BUFFER_SIZE + 1 - cursor);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*buf[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int			rd;

	rd = 0;
	if (fd < 0 || !line)
		return (-1);
	if (!buf[fd] || BUFFER_SIZE < 1)
		if (BUFFER_SIZE < 1 || !(buf[fd] = ft_calloc(BUFFER_SIZE + 1, 1)))
			return ((int)(*line = NULL) - 1);
	*line = ft_strjoin_gnl(NULL, buf[fd]);
	while (!ft_strchr(*line, '\n') && (rd = read(fd, buf[fd], BUFFER_SIZE)) > 0)
	{
		buf[fd][rd] = 0;
		*line = ft_strjoin_gnl(*line, buf[fd]);
	}
	if (rd == -1)
		return ((int)(*line = NULL) - 1);
	if (ft_strchr(buf[fd], '\n'))
	{
		*ft_strchr(*line, '\n') = 0;
		return (!moves_buff(buf[fd], count_print(buf[fd]) + 1));
	}
	free(buf[fd]);
	buf[fd] = NULL;
	return (0);
}

int				count_print(char *buff)
{
	int			count;

	count = 0;
	while (buff[count] != '\n' && count < BUFFER_SIZE)
		count++;
	return (count);
}
