/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/30 20:41:54 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_char(char *buf, char c)
{
	size_t	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (i);
		i++;
	}
	if (buf[i] == c)
		return (i);
	return (0);
}

char	*buf_2_line(char *buf, char *line)
{
	int	line_len;
	int	buf_len;
	char	*tmp;

	line_len = 0;
	buf_len = BUFFER_SIZE;
	while (line[line_len] != '\0')
		line_len++;
	tmp = malloc((sizeof(char)) * (buf_len + line_len + 1));
	if (!tmp)
		return (NULL);
	tmp[(line_len + buf_len)] = '\0';
	buf_len--;
	while (buf_len >= 0)
	{
		tmp[line_len + buf_len] = buf[buf_len];
		buf_len--;
	}
	while (line_len > 0)
	{
		tmp[line_len] = line[line_len - 1];
		line_len--;
	}
	free(line);
	return (tmp);
}
// Not sure if Buf2line will work: might be counting the '\0' char double and
// thus allocate too much memory.
//
// the line_len-- before the writing starts might need to be buf_len. LINE: 47

void	buf_update(char *buf)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = check_char(buf, '\n');
	j = check_char(buf, '\0');
	k = 0;
	while (k <= (j - i) && i)
	{
		buf[k] = buf[i + k];
		k++;
	}
	return;
}

char	*buf_split_2_line(char *buf, char *line, size_t nl_len)
{
	int		line_len;
	char	*tmp;

	line_len = 0;
	while (line[line_len])
		line_len++;
	if (!nl_len)
		nl_len = check_char(buf, '\0');
	tmp = malloc((sizeof(char)) * (line_len + nl_len));
	if (!tmp)
		return (NULL);
	while (nl_len >= 0)
	{
		tmp[line_len + nl_len] = buf[nl_len];
		nl_len--;
	}
	while (line_len >= 0)
	{
		tmp[line_len] = line[line_len];
		line_len--;
	}
	free(line);
	return (tmp);
}

char	*buf_clean(char *buf, char *line)
{
	size_t	i;
	size_t	j;

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
