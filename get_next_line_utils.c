/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/03 01:04:04 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// buf_clean: 
// Buf clean should have a check if the current fd is at the last line, 
// we can use read in this case since it won't give new output into buffer,
// 

int	check_char(char *buf, char c)
{
	int	i;

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
	return (i);
}

char	*buf_2_line(char *buf, char *line)
{
	int		line_len;
	int		buf_len;
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

void	buf_update(char *buf)
{
	int	i;
	int	j;
	int	k;

	i = check_char(buf, '\n') + 1;
	j = check_char(buf, '\0');
	k = 0;
	while (k <= (j - i) && i)
	{
		buf[k] = buf[i + k];
		k++;
	}
	return;
}

char	*buf_split_2_line(char *buf, char *line, int nl_len)
{
	int		line_len;
	char	*tmp;

	line_len = 0;
	while (line[line_len + 1])
		line_len++;
	if (!nl_len)
		nl_len = check_char(buf, '\0');
	tmp = malloc((sizeof(char)) * (line_len + nl_len));
	if (!tmp)
		return (NULL);
	while (nl_len >= 0)
	{
		tmp[line_len + nl_len + 1] = buf[nl_len];
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
			j++;
		}
		buf_update(buf);
	}
	return (line);
}

