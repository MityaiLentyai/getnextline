/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:30:00 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/28 00:42:49 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		n;

	fd = open("test_1.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	n = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", n++, line);
		free(line);
	}
	close(fd);
	return (0);
}
