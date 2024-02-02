/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:04:07 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/13 23:58:47 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

void	update_enemies(t_data *data, int x, int y)
{
	t_map	**map;
	t_map	*temp;

	map = data->map;
	temp = *map;
	while (temp)
	{
		if (temp->row == y)
		{
			if (temp->line[x] == '0')
				temp->line[x] = 'X';
			break ;
		}
		temp = temp->next;
	}
}

void	generate_enemies(t_data *data)
{
	int	x;
	int	y;
	int	total;

	total = (get_height(data->map) * get_width(data->map)) / 70;
	while (total > 0)
	{
		x = rand() % get_width(data->map);
		y = rand() % get_height(data->map);
		update_enemies(data, x, y);
		total--;
	}
}

void	draw_map_bonus(t_data *data, int init)
{
	t_map	**map;
	t_map	*temp;

	if (init)
		generate_enemies(data);
	map = data->map;
	temp = *map;
	while (temp && temp->row > data->wy)
		temp = temp->next;
	while (temp && temp->row < data->wy + MAXROW)
	{
		draw_line_bonus(data, temp->line, temp->row);
		temp = temp -> next;
	}
}
