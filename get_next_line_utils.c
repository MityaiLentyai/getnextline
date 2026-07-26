/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:36 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/26 19:02:51 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *create_node(char *str)
{
	t_list *new;

	new->content = str;
	new->next = NULL;
}

ssize_t list_length(t_list *lst)
{
	ssize_t i;

	i = 0;
	while (lst)
	{
		lst=lst->next;
		i++;
	}
	return (i);
}