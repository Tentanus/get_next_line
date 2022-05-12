/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 20:04:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/12 15:19:04 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*walk_line(int fd, char *buf, char *line)
{
	int	read_ret;

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
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buf, 0) == -1)
		return (NULL);
	line = scalloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	line = walk_line(fd, buf, line);
	if (line && !*line)
		return (free_func(line));
	return (line);
}
