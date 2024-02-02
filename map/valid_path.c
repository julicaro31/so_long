/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:32:36 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/08 12:51:57 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	go_up_down(t_map *start, int col)
{
	return (start && start->line[col] != '1' && !start->check[col]);
}

int	find_path(t_map **map, t_map *start, int col, char target)
{
	char	*line;
	int		*check;
	int		result;

	line = start->line;
	check = start->check;
	result = 0;
	change_check_status(map, start, col);
	if (line[col] == target)
		return (1);
	if (!result && line[col + 1] && line[col + 1] != '1' && !check[col + 1])
		result = find_path(map, start, col + 1, target);
	if (!result && go_up_down(start->next, col))
		result = find_path(map, start->next, col, target);
	if (!result && go_up_down(start->prev, col))
		result = find_path(map, start->prev, col, target);
	if (!result && col && line[col - 1] != '1' && !check[col - 1])
		result = find_path(map, start, col - 1, target);
	return (result);
}

int	valid_path(t_map **map)
{
	t_map	*start;

	start = find_start(map, 'P');
	return (find_path(map, start, find_character(start->line, 'P'), 'E'));
}

int	valid_path_collectibles(t_map **map)
{
	t_map	*start;
	int		index;

	start = *map;
	while (start)
	{
		index = find_character(start->line, 'C');
		if (index != -1)
		{
			restore_status(map);
			if (!find_path(map, start, index, 'P'))
				return (0);
		}
		start = start->next;
	}
	return (1);
}
