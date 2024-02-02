/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:55:44 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/14 00:35:06 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_collectibles(t_map **map)
{
	int		count;
	t_map	*temp;
	char	*line;

	count = 0;
	temp = *map;
	while (temp)
	{
		line = temp->line;
		while (*line)
		{
			if (*line == 'C')
				count++;
			line++;
		}
		temp = temp->next;
	}
	return (count);
}

int	find_window_x(t_data *data)
{
	int	wx;

	if (data->ncol <= MAXCOL)
		return (0);
	wx = data->x;
	while (wx + MAXCOL > data->ncol)
		wx--;
	if (wx + MAXCOL != data->ncol)
		wx--;
	return (wx);
}

int	find_window_y(t_data *data)
{
	int	wy;

	if (data->nrow <= MAXROW)
		return (0);
	wy = data->y;
	while (wy + MAXROW > data->nrow)
		wy--;
	if (wy + MAXROW != data->nrow)
		wy--;
	return (wy);
}

void	init_game(t_data *data, t_map **map)
{
	t_map	*start;

	data->map = map;
	start = find_start(data->map, 'P');
	data->y = start->row;
	data->x = find_character(start->line, 'P');
	data->moves = 0;
	data->collect = count_collectibles(data->map);
	data->wx = find_window_x(data);
	data->wy = find_window_y(data);
}
