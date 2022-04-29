/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 22:43:21 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/23 15:29:18 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void bufsplit2line(char *buf, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	buf2line(buf, line);
	while (buf[i] != '\n')
		i++;
	while (buf[i] && buf[i] != '\n')
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	if (buf[i] == '\n')
		buf[j] = '\0';
}

void clear_buf(char *buf, char *line)
{
	if (ft_strcheck(buf, '\n'))
		bufsplit2line(buf, line);
	else
		buf2line(buf, line);
}

int ft_strcheck(char *buf, char c)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	if (buf[i] == c)
		return (1);
	return (0);
}

void buf2line(char *buf, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[j])
		j++;
	while (buf[i] && buf[i] != '\n' )
	{
		line[j] = buf[i];
		i++;
		j++;
	}
	line[j] = '\0';
}

