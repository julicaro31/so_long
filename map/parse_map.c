/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:23:49 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/12 10:47:25 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"
#include "../include/libft.h"

int	not_valid_extension(char *map_path)
{
	return (ft_strncmp(".ber", map_path + ft_strlen(map_path) - 4, 4));
}

t_map	*parse_map(char *map_path)
{
	char	*line;
	int		row;
	t_map	*map;
	int		fd;

	if (not_valid_extension(map_path))
		return (NULL);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	map = NULL;
	row = 0;
	while (line)
	{
		if (row < 0 || ft_strlen(line) > 2147483647)
			return (free_map(&map));
		if (!add_back(&map, line, row))
			return (free_map(&map));
		line = get_next_line(fd);
		row++;
	}
	return (map);
}
