/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/16 15:44:47 by mweverli      ########   odam.nl         */
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
	while (i-- > 0)
		ptr[i] = '\0';
	return (ptr);
}

int	check_char(char *buf, char c)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	if (c == '\n')
	{
		while (buf[i])
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

char	*buf_2_line(char *buf, char *line)
{
	int		line_len;
	int		buf_len;
	char	*tmp;

	buf_len = check_char(buf, '\n');
	if (buf_len == 0)
		buf_len = check_char(buf, '\0');
	line_len = check_char(line, '\0');
	tmp = scalloc(sizeof(char), (line_len + buf_len + 1));
	if (!tmp)
		return (free(line), NULL);
	tmp[line_len + buf_len] = '\0';
	while (buf_len > 0)
	{
		buf_len--;
		tmp[line_len + buf_len] = buf[buf_len];
	}
	while (line_len > 0)
	{
		line_len--;
		tmp[line_len] = line[line_len];
	}
	free(line);
	return (tmp);
}

void	buf_update(char *buf)
{
	int	nl_plus;
	int	buf_end;
	int	i;

	nl_plus = check_char(buf, '\n');
	if (nl_plus == 0)
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
