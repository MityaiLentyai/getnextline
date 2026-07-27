/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/27 18:48:53 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	*line_len(char *stash)
{
	size_t	len_line;
	
	len_line = 0;
	if (!stash)
		return (len_line);
	while (stash[len_line] && stash[len_line] != '\n')
		len_line++;
	if (stash[len_line] == '\n')
		len_line++;
	return (len_line);
}

char 	*get_first_line(char *stash,size_t line_len)
{
	char const *line  = malloc(line_len*sizeof(char));
	
	
	return (line);
}
char *get_next_line(int fd)
{
	static char		*stash;
	char 			*line;
	size_t			line_size;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		stash = NULL;
	else
		stash = prepare_line(stash, fd);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line_size = line_len(stash);
	line = get_first_line(stash, line_size);
	stash = remove_first_line(stash, line_size);
	return (line);
}

// int main()
// {
// 	char *file = "test_1.txt";
// 	int fd = open(file,O_RDONLY);
// 	char *str = get_next_line(fd);
// 	// free(str);
// 	int i = 4;
// 	while (i-->0)
// 	{
// 		char *str = get_next_line(fd);
// 		printf ("%s",str);
// 	}
// }
