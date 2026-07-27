/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzzayats <dzzayats@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:03:33 by dzzayats          #+#    #+#             */
/*   Updated: 2026/07/26 22:27:23 by dzzayats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1.Check Static Stash: Look at your static node. Does it already contain a \n from a previous run? 
	If yes, skip reading and go straight to Step 4.	
	2. Read Loop: If no \n is found, run read(fd, buf, BUFFER_SIZE) in a loop.
	3. Append Nodes: For every read, append a new node containing
	the chunk to your linked list. Stop looping the moment you detect a \n 
	inside the chunk, or when read returns 0.	4. Free memory, return line
	4.Extract Line: Calculate the exact total length up to the first \n. 
	Allocate memory for the line, copy the characters from your linked list 
	into it, and null-terminate it.
	5. Clean & Reset Stash: Create a brand new node. 
	Copy any characters remaining after the \n into this new node. 
	Clear and free all previous nodes in your list. 
	Set your static pointer to this new "leftover" node.
	6. Return the extracted line.

	if read ever returns -1 = free everything and leave
	always check if something is in stash, to add it before hand
	Ensure the  read buffer is always null-terminated immediately 
	after reading: buf[bytes_read] = '\0'
*/


#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static ssize_t	bytes_read;
	char 			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = prepare_line(bytes_read,fd);
	
	return (line);
}

read_buffer(ssize_t bytes_read, int fd)
{
	int		current_bytes;
	char	*line;
	t_list	*node;
	
	node = create_node(line,fd);
	current_bytes = read(fd,node->current_line,BUFFER_SIZE);
	if (current_bytes < 0)
	{
		free(node);
		return (NULL);
	}
	if (!current_bytes)
	{
		node->current_line[current_bytes] ='\0';
		node->current_line[current_bytes+1] = '\n';
	}
	node->bytes_read = current_bytes;
	return (line);	
}

int main()
{
	char *file = "test_1.txt";
	int fd = open(file,O_RDONLY);
	char *str = get_next_line(fd);
	// free(str);
	int i = 4;
	while (i-->0)
	{
		char *str = get_next_line(fd);
		printf ("%s",str);
	}
}
