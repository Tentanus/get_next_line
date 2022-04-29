/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 20:04:37 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/29 21:22:22 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*walk_line(int fd, char *buf, char *line)
{
	if (buf)
		line = buf_clean(buf, line);
	if (!line || check_char(line, '\n'))
		return (line);
	while ((read(fd, buf, BUFFER_SIZE) > 0) && !(check_char(buf, '\n')))
	{
		line = buf_2_line(buf, line);
		if (!line)
			return (NULL);
	}
	return (line);
//	buf_split_2_line(buf, line, check_char(buf, '\n'));
}

char	*get_next_line(int fd)
{
	static char	*buff[BUFFER_SIZE];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buff, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line = walk_line(fd, buff, line);

	fd = 0;
	return (line);
}

/*

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
