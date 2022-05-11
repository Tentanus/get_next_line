/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/11 20:12:21 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_char(char *buf, char c)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	if (c == '\n')
	{
		while (i <= BUFFER_SIZE)
		{
			if (buf[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else
		while (buf[i])
			i++;
	return (i);
}
/*
char	*buf_2_line(char *buf, char *line)
{
	int		line_len;
	int		buf_len;
	char	*tmp;

	line_len = check_char(line, '\0');
	buf_len = BUFFER_SIZE;
	tmp = scalloc(sizeof(char), (line_len + buf_len + 1));
	if (!tmp)
		return (free_func(line));
	while (buf_len >= 0)
	{
		tmp[line_len + buf_len] = buf[buf_len];
		buf_len--;
	}
	while (line_len >= 0)
	{
		line_len--;
		tmp[line_len] = line[line_len];
	}
	free(line);
	return (tmp);
}
*/
char	*buf_2_line(char *buf, char *line)
{
	int		line_len;
	int		buf_len;
	char	*tmp;

	buf_len = check_char(buf, '\n');
	if (!buf_len)
		buf_len = check_char(buf, '\0');
	line_len = check_char(line, '\0');
	tmp = scalloc(sizeof(char), (line_len + buf_len + 1));
	if (!tmp)
		return (free_func(line));
	while (buf_len >= 0)
	{
		buf_len--;
		tmp[line_len + buf_len] = buf[buf_len];
	}
	while (line_len >= 0)
	{
		line_len--;
		tmp[line_len] = line[line_len];
	}
	free(line);
	return (tmp);
}

//buf_update:
//won't see difference between nl_plus 

void	buf_update(char *buf)
{
	int	nl_plus;
	int	buf_end;
	int	i;

	nl_plus = check_char(buf, '\n');
	if (!nl_plus)
	{
		buf[0] = '\0';
		return ;
	}
	buf_end = check_char(buf, '\0');
	i = 0;
	while (i <= (buf_end - nl_plus))
	{
		buf[i] = buf[nl_plus + i];
		i++;
	}
	buf[i] = '\0';
	return ;
}

char	*buf_clean(char *buf, char *line)
{
	int	nl;

	nl = check_char(buf, '\n');
	if (nl == 0)
		line = buf_2_line(buf, line);
	else
	{
		line = buf_2_line(buf, line);
		buf_update(buf);
	}
	return (line);
}
