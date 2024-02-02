/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:53:00 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/12 14:00:04 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/so_long.h"

void	*convert_file(void *mlx, char *file, int *x, int *y)
{
	return (mlx_xpm_file_to_image(mlx, file, x, y));
}

void	**open_images(t_data *data)
{
	void	**img;
	t_img	temp;

	img = malloc(sizeof(void *) * 9);
	if (!img)
		return (NULL);
	temp.img = convert_file(data->mlx, "assets/ice.xpm", &temp.x, &temp.y);
	img[0] = temp.img;
	temp.img = convert_file(data->mlx, "assets/santa.xpm", &temp.x, &temp.y);
	img[1] = temp.img;
	temp.img = convert_file(data->mlx, "assets/gift.xpm", &temp.x, &temp.y);
	img[2] = temp.img;
	temp.img = convert_file(data->mlx, "assets/nr_exit.xpm", &temp.x, &temp.y);
	img[3] = temp.img;
	temp.img = convert_file(data->mlx, "assets/snow.xpm", &temp.x, &temp.y);
	img[4] = temp.img;
	temp.img = convert_file(data->mlx, "assets/santa_e.xpm", &temp.x, &temp.y);
	img[5] = temp.img;
	temp.img = convert_file(data->mlx, "assets/r_exit.xpm", &temp.x, &temp.y);
	img[6] = temp.img;
	temp.img = convert_file(data->mlx, "assets/hole.xpm", &temp.x, &temp.y);
	img[7] = temp.img;
	img[8] = NULL;
	return (img);
}
