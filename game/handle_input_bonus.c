/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:52:07 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/14 00:33:29 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
#include "../include/so_long.h"
#include "../include/ft_printf.h"

void	go_left(t_data *data)
{
	if (possible_move(data, data->x - 1, data->y))
	{
		data->moves += 1;
		data->x -= 1;
		update(data);
		if (!left_render(data))
		{
			update_current_img(data, data->x + 1, data->y);
			update_new_img(data, data->x, data->y);
		}
		check_if_finished(data);
		check_enemy(data);
	}
}

void	go_right(t_data *data)
{
	if (possible_move(data, data->x + 1, data->y))
	{
		data->moves += 1;
		data->x += 1;
		update(data);
		if (!right_render(data))
		{
			update_current_img(data, data->x - 1, data->y);
			update_new_img(data, data->x, data->y);
		}
		check_if_finished(data);
		check_enemy(data);
	}
}

void	go_up(t_data *data)
{
	if (possible_move(data, data->x, data->y - 1))
	{
		data->moves += 1;
		data->y -= 1;
		update(data);
		if (!up_render(data))
		{
			update_current_img(data, data->x, data->y + 1);
			update_new_img(data, data->x, data->y);
		}
		check_if_finished(data);
		check_enemy(data);
	}
}

void	go_down(t_data *data)
{
	if (possible_move(data, data->x, data->y + 1))
	{
		data->moves += 1;
		data->y += 1;
		update(data);
		if (!down_render(data))
		{
			update_current_img(data, data->x, data->y - 1);
			update_new_img(data, data->x, data->y);
		}
		check_if_finished(data);
		check_enemy(data);
	}
}

int	handle_input_bonus(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Bye!\n");
		clean_exit(data->map, data, 3);
	}
	else if (keysym == 97)
		go_left(data);
	else if (keysym == 100)
		go_right(data);
	else if (keysym == 119)
		go_up(data);
	else if (keysym == 115)
		go_down(data);
	return (0);
}
