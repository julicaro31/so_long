/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partial_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:27:10 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/14 00:35:21 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	right_render(t_data *data)
{
	if (data->x == data->wx + MAXCOL - 1)
	{
		data->wx += 1;
		draw_map(data);
		if (is_character(data, data->x, data->y, 'E'))
			display_img(data, data->img[5], data->x, data->y);
		update_exit(data);
		return (1);
	}
	return (0);
}

int	left_render(t_data *data)
{
	if (data->x == data->wx)
	{
		data->wx -= 1;
		draw_map(data);
		if (is_character(data, data->x, data->y, 'E'))
			display_img(data, data->img[5], data->x, data->y);
		update_exit(data);
		return (1);
	}
	return (0);
}

int	up_render(t_data *data)
{
	if (data->y == data->wy)
	{
		data->wy -= 1;
		draw_map(data);
		if (is_character(data, data->x, data->y, 'E'))
			display_img(data, data->img[5], data->x, data->y);
		update_exit(data);
		return (1);
	}
	return (0);
}

int	down_render(t_data *data)
{
	if (data->y == data->wy + MAXROW - 1)
	{
		data->wy += 1;
		draw_map(data);
		if (is_character(data, data->x, data->y, 'E'))
			display_img(data, data->img[5], data->x, data->y);
		update_exit(data);
		return (1);
	}
	return (0);
}
