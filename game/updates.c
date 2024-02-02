/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:38:08 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/13 22:37:01 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include "../include/so_long.h"
#include "../include/ft_printf.h"

void	update_current_img(t_data *data, int x, int y)
{
	if (is_character(data, x, y, 'E'))
		display_img(data, data->img[3], x, y);
	else
		display_img(data, data->img[4], x, y);
}

void	update_new_img(t_data *data, int x, int y)
{
	if (is_character(data, x, y, 'E'))
		display_img(data, data->img[5], x, y);
	else
		display_img(data, data->img[1], x, y);
}

void	update_colectible(t_data *data)
{
	t_map	**map;
	t_map	*temp;

	map = data->map;
	if (is_character(data, data->x, data->y, 'C'))
	{
		temp = *map;
		while (temp && temp->row != data->y)
			temp = temp->next;
		temp->line[data->x] = '0';
		data->collect -= 1;
	}
}

void	update_exit(t_data *data)
{
	t_map	*exit;
	int		col;

	if (data->collect == 0)
	{
		exit = find_start(data->map, 'E');
		col = find_character(exit->line, 'E');
		display_img(data, data->img[6], col, exit->row);
	}
}

void	update(t_data *data)
{
	update_colectible(data);
	update_exit(data);
	ft_printf("total moves: %d\n", data->moves);
}
