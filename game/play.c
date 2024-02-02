/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:05:36 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/13 18:38:37 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/so_long.h"

void	set_size(t_data *data, t_map **map)
{
	data->nrow = get_height(map);
	data->ncol = get_width(map);
	if (data->nrow <= MAXROW)
		data->y = data->nrow * IMG_SIZE;
	else
		data->y = MAXROW * IMG_SIZE;
	if (data->ncol <= MAXCOL)
		data->x = data->ncol * IMG_SIZE;
	else
		data->x = MAXCOL * IMG_SIZE;
}

void	play(t_map **map)
{
	t_data	data;
	void	**img;

	data.mlx = mlx_init();
	if (!data.mlx)
		clean_exit(map, &data, 0);
	set_size(&data, map);
	data.mlx_win = mlx_new_window(data.mlx, data.x, data.y, "SO LONG");
	if (!data.mlx_win)
		clean_exit(map, &data, 1);
	init_game(&data, map);
	img = open_images(&data);
	if (!img)
		clean_exit(map, &data, 2);
	data.img = img;
	draw_map(&data);
	mlx_hook(data.mlx_win, 02, 1L << 0, handle_input, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_game, &data);
	mlx_loop(data.mlx);
}
