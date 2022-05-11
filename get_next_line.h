/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:58:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/05/11 19:51:07 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Switch around for logic

# if BUFFER_SIZE > 1000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

//FUNCTIONS
int		check_char(char *buf, char c);
char	*get_next_line(int fd);
char	*buf_clean(char *buf, char *line);
char	*buf_2_line(char *buf, char *line);
//char	*buf_split_2_line(char *buf, char *line);
void	buf_update(char *buf);
void	*free_func(char *line);
void	*scalloc(size_t nitems, size_t size);

#endif

/*
 * To do list in get_next_line:
 *
 *
 * Checklist of walking the line:
 *
 * -check if buf excists
 * 		check if contains \n
 * 			buf split 2 line
 * 			update buf
 * 		no
 * 			buf 2 line
 * while read 
 *
 *


// read returns the total amount of bites read. meaning
// read(fd, buf[x], x) (x = 10):
// will return 10 when in the middle of a file.
//
// will return 5 when partially at the end of the file 
// ex: buf[]= "the end but"
// 
*/
