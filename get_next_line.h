/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 18:58:05 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/29 21:22:17 by mweverli      ########   odam.nl         */
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

int		check_char(char *buf, char c);
char	*buf_2_line(char *buf, char *line);
char	*buf_clean(char *buf, char *line);
char	*get_next_line(int fd);

#endif
