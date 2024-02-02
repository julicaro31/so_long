/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:57:59 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/09 13:24:47 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/libft.h"

int	is_valid_character(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
}

int	get_index(char c)
{
	if (c == 'C')
		return (0);
	else if (c == 'E')
		return (1);
	else if (c == 'P')
		return (2);
	else
		return (-1);
}

int	check_first_last_wall(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	check_side_wall(char *line)
{
	return (line[0] == '1' && line[ft_strlen(line) - 1] == '1');
}
