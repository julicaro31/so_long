/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:42:17 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/11 18:05:06 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../include/so_long.h"
#include "../include/ft_printf.h"

void	clean_exit(t_map **map, t_data *data, int i)
{
	if (i == 3)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (i == 2 | i == 3)
		free_images(data);
	if (i == 1 || i == 2 || i == 3)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map(map);
	exit(0);
}

int	exit_game(t_data *data)
{
	ft_printf("Bye!\n");
	clean_exit(data->map, data, 3);
	return (1);
}
