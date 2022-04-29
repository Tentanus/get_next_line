/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/29 21:22:20 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_char(char *buf, char c)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
		if (buf[i] == c)
			return (i);
	while (buf[i] == c)
		return (i);
	return (0);
}

char	*buf_2_line(char *buf, char *line)
{
	int		line_len;
	int		buf_len;
	char	*tmp;

	line_len = 0;
	buf_len = BUFFER_SIZE;
	while (line)
		line_len++;
	tmp = malloc((sizeof(char)) * (buf_len + line_len + 1));
	if (!tmp)
		return (NULL);
	tmp[(line_len + buf_len)] = '\0';
	line_len--; // this might need to be buf_len;
	while (buf_len >= 0)
	{
		tmp[line_len + buf_len] = buf[buf_len];
		buf_len--;
	}
	while (line_len >= 0)
	{
		tmp[line_len + buf_len] = line[line_len];
		line_len--;
	}
	free(line);
	return (line);
}

/*
void	buf_split_2_line(char *buf, char *line, int nl)
{
	
}
*/

char	*buf_clean(char *buf, char *line)
{
	int	i;
	int	j;

	i = check_char(buf, '\n');
	j = 0;
	if (i == 0)
	{
		buf_2_line(buf, line);
		return (line);
	}
	else
	{
		line = malloc((sizeof(char)) * (i + 1));
		if (!line)
			return (NULL);
		line[i] = '\0';
		while (j <= i)
		{
			line[j] = buf[j];
			buf[j] = buf[i + j + 1];
			j++;
		}
	}
	return (line);
}

// Edge case: when there is a long buffer -> the while loop won't propperly
// update the entire buffer
// e.g.
// buf: 		 "ere\nAnd later that\0"
// updated buf:	 "And  And later that\0"
