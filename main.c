/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_main.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mweverli <mweverli@codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 15:46:33 by mweverli      #+#    #+#                 */
/*   Updated: 2022/04/30 19:09:32 by mweverli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	char	*fn3 = "/Users/mweverli/files/get_next_line/Text_files/testing.txt";
//	char	*fn4 = "/Users/mweverli/files/get_next_line/Text_files/top_chars_network.txt";
//	char	*fn5 = "/Users/mweverli/files/get_next_line/Text_files/EpisodeIV_dialogues.txt";

	int i = 3;
	int		fd3 = open(fn3, O_RDONLY);
//	int		fd4 = open(fn4, O_RDONLY);
//	int		fd5 = open(fn5, O_RDONLY);

	while(i)
	{
		char	*next_line = get_next_line(fd3);
		printf("-------========--------\nthe next line:\n|%s|\n\n", next_line);
		free(next_line);
		i--;
	}
	return (0);
}

//ssize_t read(int fd, void *buf, size_t nbytes);

