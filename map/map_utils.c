/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:21:04 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/09 13:12:11 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

t_map	*new_node(char *line, int row)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->check = ft_calloc(ft_strlen(line), sizeof(int));
	if (!new -> check)
		return (NULL);
	new->line = line;
	new->row = row;
	new->next = NULL;
	return (new);
}

t_map	*add_back(t_map **head, char *line, int row)
{
	t_map	*new;
	t_map	*temp;

	new = new_node(line, row);
	temp = *head;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
	{
		*head = new;
		new->prev = NULL;
	}
	return (new);
}

t_map	*free_map(t_map **head)
{
	t_map	*temp;
	t_map	*current;

	current = *head;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp->line);
		temp->line = NULL;
		free(temp->check);
		temp->check = NULL;
		free(temp);
	}
	return (NULL);
}

int	get_height(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp->next)
		temp = temp->next;
	return (temp->row + 1);
}

int	get_width(t_map **map)
{
	t_map	*temp;

	temp = *map;
	return (ft_strlen(temp->line));
}
