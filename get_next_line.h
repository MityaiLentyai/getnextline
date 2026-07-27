/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:30 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/28 00:40:00 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	ssize_t			bytes_read;
	ssize_t			current_byte;
	char			*current_line;
	char			*stashed_line;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	init_node(t_list *node, char *buf, ssize_t n);
t_list	*create_node(int fd);
t_list	*read_until_nl(t_list *stash, int fd);
char	*copy_line_from_lst(t_list *lst, size_t len);
void	advance_stash(t_list **stash, size_t len);
int		lst_has_newline(t_list *lst);
size_t	lst_line_len(t_list *lst);
void	lst_clear(t_list **lst);

#endif
