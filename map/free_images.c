/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:21:48 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/11 14:05:29 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/so_long.h"

int	free_images(t_data *data)
{
	void	**img;

	img = data->img;
	while (*img)
	{
		mlx_destroy_image(data->mlx, *img);
		img++;
	}
	free(data->img);
	return (0);
}
