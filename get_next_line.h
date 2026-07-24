/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:30 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/22 21:52:38 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);


int main()
{
	const char *file = "test_1.txt";
	open(file,O_RDONLY);
}