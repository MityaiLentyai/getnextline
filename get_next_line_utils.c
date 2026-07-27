/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:36 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/26 22:29:50 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *create_node(char *str, int fd)
{
    t_list *new;

    new = malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new->bytes_read = read(fd, str, BUFFER_SIZE);
    new->current_byte = new->bytes_read;
    new->current_line = str;
    new->stashed_line = NULL;
    new->next = NULL;
    return (new);
}
t_list *add_node_back(t_list *prev,int fd)
{

	
}
ssize_t list_length(t_list *lst)
{
    ssize_t i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}