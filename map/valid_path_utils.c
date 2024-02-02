/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:31:19 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/08 12:51:33 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

int	find_character(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_map	*find_start(t_map **map, char c)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		if (find_character(temp->line, c) != -1)
			break ;
		temp = temp->next;
	}
	return (temp);
}

void	change_check_status(t_map **map, t_map *start, int col)
{
	t_map	*temp;

	temp = *map;
	while (temp && temp->row != start->row)
		temp = temp->next;
	if (temp)
		temp->check[col] = 1;
}

void	restore_line_status(int *check, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		check[i] = 0;
		i++;
	}
}

void	restore_status(t_map **map)
{
	t_map	*temp;

	temp = *map;
	while (temp)
	{
		restore_line_status(temp->check, ft_strlen(temp->line));
		temp = temp->next;
	}
}
