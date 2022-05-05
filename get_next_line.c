/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 20:04:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/05 18:22:39 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*scalloc(size_t nitems, size_t size)
{
	char	*ptr;
	int		i;

	i = (nitems * size);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	while (i >= 0)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}

void	*free_func(char *line)
{
	free(line);
	return (NULL);
}

char	*walk_line(int fd, char *buf, char *line)
{
	int	read_ret;

	if (*buf)
		line = buf_clean(buf, line);
	if (!line || check_char(line, '\n'))
		return (line);
	read_ret = read(fd, buf, BUFFER_SIZE);
	buf[read_ret] = '\0';
	while (read_ret == BUFFER_SIZE && !(check_char(buf, '\n')))
	{
		line = buf_2_line(buf, line);
		read_ret = read(fd, buf, BUFFER_SIZE);
		buf[read_ret] = '\0';
	}
	line = buf_split_2_line(buf, line, check_char(buf, '\n'));
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
	return (line);
}
