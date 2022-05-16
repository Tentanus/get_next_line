/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:58:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/16 15:52:15 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//FUNCTIONS
char	*get_next_line(int fd);
void	*scalloc(size_t nitems, size_t size);
void	*free_func(char *line);
int		check_char(char *buf, char c);
char	*buf_2_line(char *buf, char *line);
void	buf_update(char *buf);

#endif
