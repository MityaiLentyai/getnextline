/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/26 19:08:17 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static ssize_t	bytes_read;
	ssize_t i;

	i = 0;
	
	char *str = malloc((BUFFER_SIZE+1)*sizeof(char));
	if (NULL == str)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd,str,BUFFER_SIZE);
		
	}
	if (0 == bytes_read && *str == '\n')
	 	return (str);
	*(str + bytes_read) = '\n';
	return (str);
}

int main()
{
	char *file = "test_1.txt";
	int fd = open(file,O_RDONLY);
	char *str = get_next_line(fd);
	// free(str);
	while (!read(fd,str,BUFFER_SIZE))
		printf ("%s",str);
}
