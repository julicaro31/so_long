/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:13:58 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/06 16:59:42 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	add_chars(t_list **line, char *buffer)
{
	while (*buffer)
	{
		if (!ft_lstadd_back(line, *buffer))
		{
			ft_lstclear(line);
			return ;
		}
		buffer++;
	}
}

size_t	get_size_line(t_list **list)
{
	size_t	size_line;
	t_list	*line;

	line = *list;
	size_line = 0;
	while (line && line -> content != '\n')
	{
		size_line++;
		line = line -> next;
	}
	return (size_line);
}

char	*list_to_str(t_list **list)
{
	char	*str;
	t_list	*line;
	size_t	i;

	str = (char *)malloc(get_size_line(list) + 1);
	if (!str)
	{
		ft_lstclear(list);
		return (NULL);
	}
	line = *list;
	i = 0;
	while (line && line -> content != '\n')
	{
		str[i] = line -> content;
		line = line -> next;
		i++;
	}
	str[i] = '\0';
	reduce_lst(list);
	return (str);
}

int	get_line(int fd, t_list **list)
{
	char	*buffer;
	ssize_t	size;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		ft_lstclear(list);
		return (0);
	}
	size = read(fd, buffer, BUFFER_SIZE);
	if (!size)
	{
		free(buffer);
		return (1);
	}
	buffer[size] = '\0';
	add_chars(list, buffer);
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;
	int				ready;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	line = NULL;
	ready = 0;
	while (!line_complete(&list) && !ready)
	{
		if (get_line(fd, &list))
			ready = 1;
		if (!list)
			return (NULL);
	}
	line = list_to_str(&list);
	return (line);
}
