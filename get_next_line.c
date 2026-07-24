/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/24 16:30:50 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BEUFF
# define BEUFF 100
#endif

char *get_next_line(int fd)
{
	char *str = malloc(BEUFF*sizeof(char));
	// char *file = "test_1.txt";
	read(fd,str,BEUFF);
	// write (fd,&file,5);
	return (str);
}

int main()
{
	char *file = "test_1.txt";
	int fd = open(file,O_RDONLY);
	char *str = get_next_line(fd);
	printf ("%s",str);
	// printf("%zd",read(fd,&file,5));
}