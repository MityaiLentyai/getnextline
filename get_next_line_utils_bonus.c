/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:36 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/28 13:38:41 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_node(t_list *node, char *buf, ssize_t n)
{
	buf[n] = '\0';
	node->current_line = buf;
	node->bytes_read = n;
	node->current_byte = 0;
	node->stashed_line = NULL;
	node->next = NULL;
}

t_list	*create_node(int fd)
{
	t_list	*new;
	char	*buf;
	ssize_t	n;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
	{
		free(buf);
		return (NULL);
	}
	n = read(fd, buf, BUFFER_SIZE);
	if (n <= 0)
	{
		free(buf);
		free(new);
		return (NULL);
	}
	init_node(new, buf, n);
	return (new);
}

int	lst_has_newline(t_list *lst)
{
	ssize_t	pos;

	while (lst)
	{
		pos = lst->current_byte;
		while (pos < lst->bytes_read)
		{
			if (lst->current_line[pos] == '\n')
				return (1);
			pos++;
		}
		lst = lst->next;
	}
	return (0);
}

size_t	lst_line_len(t_list *lst)
{
	size_t	len;
	ssize_t	pos;

	len = 0;
	while (lst)
	{
		pos = lst->current_byte;
		while (pos < lst->bytes_read)
		{
			len++;
			if (lst->current_line[pos] == '\n')
				return (len);
			pos++;
		}
		lst = lst->next;
	}
	return (len);
}

void	lst_clear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->current_line);
		free(*lst);
		*lst = tmp;
	}
}
