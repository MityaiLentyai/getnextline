/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:30 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/24 17:26:48 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char *content,
	s_list *next,
}	t_list

char *get_next_line(int fd);
