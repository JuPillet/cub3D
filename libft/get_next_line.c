/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpillet <jpillet@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 11:20:17 by jpillet           #+#    #+#             */
/*   Updated: 2021/04/15 16:27:41 by jpillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_gnl_status(int eof, char *line, int fd, const char *file)
{
	if (eof == -1)
	{
		printf("Error\n");
		close(fd);
		if (line)
			free(line);
		ft_error("program has failed to read in the file :\n", file);
		return (FALSE);
	}
	return (TRUE);
}

int		ft_gnl_return_value(t_buffer *buff)
{
	if ((buff->buffinc) == (buff->readlen) && (buff->readlen) < BUFFER_SIZE)
	{
		(buff->buffinc) = 0;
		return (0);
	}
	else if ((buff->buffer)[(buff->buffinc)] == '\n')
	{
		(buff->buffinc)++;
		return (1);
	}
	return (2);
}

int		ft_gnl_line_maker(t_buffer *buff, ssize_t *linelen, char **line)
{
	char			*delline;
	ssize_t			mallinc;

	mallinc = 0;
	while (buff->buffer[buff->buffinc + mallinc] != '\n'
		&& (buff->buffinc + mallinc) < buff->readlen)
		mallinc++;
	if (*linelen)
		delline = *line;
	*line = malloc((*linelen) + mallinc + 1);
	if (!(*line))
		return (-1);
	if (*linelen > 0)
	{
		*linelen = 0;
		while (delline[(*linelen)])
		{
			(*line)[(*linelen)] = delline[(*linelen)];
			(*linelen)++;
		}
		free(delline);
	}
	while (buff->buffer[buff->buffinc] != '\n' && buff->buffinc < buff->readlen)
		(*line)[(*linelen)++] = buff->buffer[buff->buffinc++];
	(*line)[(*linelen)] = '\0';
	return ((ft_gnl_return_value(buff)));
}

int		get_next_line(int fd, char **line)
{
	static t_buffer		buff[256];
	ssize_t				linelen;
	int					rtnval;

	linelen = 0;
	rtnval = 2;
	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 255) || !line)
		return (-1);
	while (rtnval == 2)
	{
		if (buff[fd].buffinc == buff[fd].readlen)
			buff[fd].buffinc = 0;
		if (!buff[fd].buffinc)
		{
			buff[fd].readlen = read(fd, buff[fd].buffer, BUFFER_SIZE);
			if (buff[fd].readlen == -1)
			{
				buff[fd].readlen = 0;
				return (-1);
			}
		}
		rtnval = ft_gnl_line_maker(&(buff[fd]), &linelen, line);
	}
	return (rtnval);
}
