/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:58:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/12 15:19:07 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//FUNCTIONS
int		check_char(char *buf, char c);
char	*get_next_line(int fd);
char	*buf_2_line(char *buf, char *line);
void	buf_update(char *buf);
void	*free_func(char *line);
void	*scalloc(size_t nitems, size_t size);

#endif
