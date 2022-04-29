/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:58:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/23 15:29:16 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENELI_H
# define GENELI_H

# include <stdio.h>

# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

//Prototypes

int ft_strcheck(char *buf, char c);
void buf2line(char *buf, char *line);
void bufsplit2line(char *buf, char *line);
void clear_buf(char *buf, char *line);
char *get_next_line(int fd);

#endif
