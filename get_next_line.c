/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/24 19:48:28 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BEUFF
# define BEUFF 100
#endif

char *get_next_line(int fd)
{
	ssize_t bytes_read;
	
	
	char *str = malloc(BEUFF*sizeof(char));
	bytes_read = read(fd,str,BEUFF);
	return (str);
}

int main()
{
	char *file = "test_1.txt";
	int fd = open(file,O_RDONLY);
	char *str = get_next_line(-1);
	free(str);
	printf ("%s",str);
}

