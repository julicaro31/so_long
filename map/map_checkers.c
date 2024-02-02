/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:01:30 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/13 18:32:12 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/ft_printf.h"
#include "../include/libft.h"

int	correct_characters(t_map **map)
{
	t_map	*temp;
	char	*line;
	int		characters[3];

	characters[0] = 0;
	characters[1] = 0;
	characters[2] = 0;
	temp = *map;
	while (temp)
	{
		line = temp->line;
		while (*line)
		{
			if (!is_valid_character(*line))
				return (2);
			if (get_index(*line) != -1)
				characters[get_index(*line)]++;
			line++;
		}
		temp = temp->next;
	}
	if (characters[1] != 1 || characters[2] != 1)
		return (3);
	return (characters[0] > 0);
}

int	is_rectangular(t_map **map)
{
	size_t	width;
	size_t	height;
	t_map	*temp;

	temp = *map;
	width = ft_strlen(temp->line);
	height = get_height(map);
	while (temp)
	{
		if (width != ft_strlen(temp->line))
			return (0);
		temp = temp->next;
	}
	return (height != width);
}

int	is_surrounded(t_map **map)
{
	t_map	*temp;
	int		sur;

	temp = *map;
	sur = 1;
	while (temp && sur)
	{
		if (temp->row == 0 || temp->next == NULL)
			sur = check_first_last_wall(temp->line);
		else
			sur = check_side_wall(temp->line);
		temp = temp->next;
	}
	return (sur);
}

int	error_msg(int i)
{
	ft_printf("Error\n");
	if (i == 0)
		ft_printf("Empty or invalid file\n");
	else if (i == 1)
		ft_printf("There are no collectibles\n");
	else if (i == 2)
		ft_printf("The characters are not correct\n");
	else if (i == 3)
		ft_printf("There are duplicates or missing characters\n");
	else if (i == 4)
		ft_printf("The map is not rectangular\n");
	else if (i == 5)
		ft_printf("The map is not surrounded by walls\n");
	else if (i == 6)
		ft_printf("There is no valid path\n");
	return (0);
}

int	is_valid_map(t_map **map)
{
	if (*map == NULL)
		return (error_msg(0));
	if (!correct_characters(map))
		return (error_msg(1));
	if (correct_characters(map) == 2)
		return (error_msg(2));
	if (correct_characters(map) == 3)
		return (error_msg(3));
	if (!is_rectangular(map))
		return (error_msg(4));
	if (!is_surrounded(map))
		return (error_msg(5));
	if (!valid_path(map) || !valid_path_collectibles(map))
		return (error_msg(6));
	return (1);
}
