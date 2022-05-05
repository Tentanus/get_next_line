/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/05 18:12:14 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_char(char *buf, char c)
{
	int	i;

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
	int		line_len;
	int		buf_len;
	char	*tmp;

	line_len = (check_char(line, '\0') - 1);
	buf_len = BUFFER_SIZE;
	tmp = scalloc(sizeof(char), (line_len + buf_len + 1));
	if (!tmp)
		return (free_func(line));
	while (buf_len >= 0)
	{
		tmp[line_len + buf_len + 1] = buf[buf_len];
		buf_len--;
	}
	while (line_len >= 0)
	{
		tmp[line_len] = line[line_len];
		line_len--;
	}
	free(line);
	return (tmp);
}

char	*buf_split_2_line(char *buf, char *line, int nl)
{
	int		line_len;
	char	*tmp;

	line_len = (check_char(line, '\0') - 1);
	tmp = scalloc(sizeof(char), (line_len + nl + 1));
	if (!tmp)
		return (free_func(line));
	while (nl >= 0)
	{
		tmp[line_len + nl + 1] = buf[nl];
		nl--;
	}
	while (line_len >= 0)
	{
		tmp[line_len] = line[line_len];
		line_len--;
	}
	free(line);
	return (tmp);
}

void	buf_update(char *buf)
{
	int	nl_plus;
	int	buf_end;
	int	i;

	nl_plus = (check_char(buf, '\n') + 1);
	buf_end = check_char(buf, '\0');
	i = 0;
	while (i <= (buf_end - nl_plus))
	{
		buf[i] = buf[nl_plus + i];
		i++;
	}
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
		line = buf_split_2_line(buf, line, nl);
		buf_update(buf);
	}
	return (line);
}
