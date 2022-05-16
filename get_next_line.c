/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 20:04:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/16 15:56:40 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_ret;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buf, 0) == -1)
		return (NULL);
	line = scalloc(sizeof(char), 1);
	if (*buf)
		line = buf_2_line(buf, line);
	while (line && !(check_char(line, '\n')))
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
			return (free_func(line));
		buf[read_ret] = '\0';
		line = buf_2_line(buf, line);
		if (read_ret < BUFFER_SIZE)
			break ;
	}
	buf_update(buf);
	if (read_ret == 0 && *line == '\0')
		return (free_func(line));
	return (line);
}
