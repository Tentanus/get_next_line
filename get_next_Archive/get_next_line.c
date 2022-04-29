/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 20:04:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/26 19:06:39 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*walk_line(char *buf, char *line, int fd)
{
	if (!(ft_strcheck(buf, '\n')))
		buf2line(buf, line);
	while (!(ft_strcheck(buf, '\n')) && read(fd, buf, BUFFER_SIZE))
		buf2line(buf, line);
	if (ft_strcheck(buf, '\n'))
		bufsplit2line(buf, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
//	line = malloc(sizeof(char*));
//	if (!line)
//		return (NULL);
	if (*buf)
		clear_buf(buf, line);
	if (!*buf)
		if (fd < 0 || fd > OPEN_MAX || read(fd, buf, BUFFER_SIZE) == -1)
			return (NULL);
	line = walk_line(buf, line, fd);
	return (line);
}

/*
To Do's:
- when we go into clean_buf line is yet to be initialized. aka restructure has
  happen. (Line 32 ; get_next_line.c)
- I'm not sure if the line is proparly ended with a '\n' and then a '\0'. check
  buf2split (Utils)
- clear_buf




Open return values:



																				
Read Return values:
non-negative
Upon succesful completion, indicating the total bytes actually read.

-1
if it fails



First Try: Walk Line:
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(ft_strcheck(buf, '\n')))
		buf2line(buf, line);
	while (!(ft_strcheck(buf, '\n')) && read(fd, buf, BUFFER_SIZE))
		buf2line(buf, line);
	if (ft_strcheck(buf, '\n'))
	{
		buf2line(buf, line);
		while (buf[i] != '\n')
			i++;
		while (buf[i])
		{
			buf[j] = buf [i];
			i++;
			j++;
		}
		buf[j] = '\0';
	}
	return (line);
}
*/
