/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 20:04:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/03 18:20:01 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*walk_line(int fd, char *buf, char *line)
{
	int	return_read;

	if (*buf)
		line = buf_clean(buf, line);
	if (!line || check_char(line, '\n'))
		return (line);
	return_read = read(fd, buf, BUFFER_SIZE); 
	while ((return_read > 0) && (check_char(buf, '\n') == 
				BUFFER_SIZE))
	{
		line = buf_2_line(buf, line);
		if (!line)
			return (NULL);
		return_read = read(fd, buf, BUFFER_SIZE); 
	}

	line = buf_split_2_line(buf, line, check_char(buf, '\n'));
	buf_update(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buff, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line = walk_line(fd, buff, line);
	return (line);
}

void	*calloc(size_t nitems, size_t size)
{
	char	*ptr;
	int i;

	i = (nitems * size);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	while (i)
	{
		ptr[i] = '\0';
		i--;
	}
	return (ptr);
}
