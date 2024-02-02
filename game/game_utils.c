/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:41:31 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/11 16:44:32 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"

t_map	*find_row(t_map **map, int row)
{
	int		i;
	t_map	*temp;

	i = 0;
	temp = *map;
	while (temp && temp->row != row)
		temp = temp->next;
	return (temp);
}

int	possible_move(t_data *data, int x, int y)
{
	t_map	*map;

	map = find_row(data->map, y);
	return (map->line[x] != '1');
}

int	is_character(t_data *data, int x, int y, char c)
{
	t_map	*map;

	map = find_row(data->map, y);
	return (map->line[x] == c);
}

void	check_if_finished(t_data *data)
{
	if (!data->collect && is_character(data, data->x, data->y, 'E'))
	{
		ft_printf("You won! Merry Christmas :)");
		clean_exit(data->map, data, 3);
	}
}
