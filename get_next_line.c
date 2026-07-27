/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/28 00:40:00 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*read_until_nl(t_list *stash, int fd)
{
	t_list	*new;
	t_list	*tmp;

	if (stash && lst_has_newline(stash))
		return (stash);
	while (1)
	{
		new = create_node(fd);
		if (!new)
			return (stash);
		if (!stash)
			stash = new;
		else
		{
			tmp = stash;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		if (lst_has_newline(stash))
			return (stash);
	}
}

char	*copy_line_from_lst(t_list *lst, size_t len)
{
	char	*line;
	size_t	j;
	ssize_t	pos;

	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < len && lst)
	{
		pos = lst->current_byte;
		while (j < len && pos < lst->bytes_read)
			line[j++] = lst->current_line[pos++];
		lst = lst->next;
	}
	line[j] = '\0';
	return (line);
}

void	advance_stash(t_list **stash, size_t len)
{
	t_list	*node;
	size_t	j;

	j = 0;
	while (*stash && j < len)
	{
		while (*stash && j < len
			&& (*stash)->current_byte < (*stash)->bytes_read)
		{
			(*stash)->current_byte++;
			j++;
		}
		if (*stash && (*stash)->current_byte >= (*stash)->bytes_read)
		{
			node = *stash;
			*stash = (*stash)->next;
			free(node->current_line);
			free(node);
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		lst_clear(&stash);
		return (NULL);
	}
	stash = read_until_nl(stash, fd);
	len = lst_line_len(stash);
	if (len == 0)
	{
		lst_clear(&stash);
		return (NULL);
	}
	line = copy_line_from_lst(stash, len);
	if (!line)
		return (NULL);
	advance_stash(&stash, len);
	return (line);
}
