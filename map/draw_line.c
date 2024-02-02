/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:10:42 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/13 23:55:24 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/so_long.h"

void	display_img(t_data *data, void *img_ptr, int x, int y)
{
	int	sx;
	int	sy;

	sx = (x - data->wx) * IMG_SIZE;
	sy = (y - data->wy) * IMG_SIZE;
	mlx_put_image_to_window(data->mlx, data->mlx_win, img_ptr, sx, sy);
}

void	draw_line(t_data *data, char *line, int row)
{
	void	**img;
	int		i;

	i = data->wx;
	img = data->img;
	while (line[i] && i < data->wx + MAXCOL)
	{
		if (row == data->y && i == data->x)
			display_img(data, img[1], i, row);
		else if (line[i] == '1')
			display_img(data, img[0], i, row);
		else if (line[i] == 'P')
			display_img(data, img[4], i, row);
		else if (line[i] == 'C')
			display_img(data, img[2], i, row);
		else if (line[i] == 'E')
			display_img(data, img[3], i, row);
		else if (line[i] == 'X')
			display_img(data, img[7], i, row);
		else if (line[i])
			display_img(data, img[4], i, row);
		i++;
	}
}
