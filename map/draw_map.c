/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:05:49 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/13 21:42:25 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_map(t_data *data)
{
	t_map	**map;
	t_map	*temp;

	map = data->map;
	temp = *map;
	while (temp && temp->row > data->wy)
		temp = temp->next;
	while (temp && temp->row < data->wy + MAXROW)
	{
		draw_line(data, temp->line, temp->row);
		temp = temp -> next;
	}
}
