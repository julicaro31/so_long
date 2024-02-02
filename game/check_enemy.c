/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:53:44 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/12 15:04:39 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"

void	check_enemy(t_data *data)
{
	if (is_character(data, data->x, data->y, 'X'))
	{
		ft_printf("You lost! The gifts won't be delivered :(");
		clean_exit(data->map, data, 3);
	}
}
