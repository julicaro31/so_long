/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:01:48 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/12 14:02:17 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int ac, char *argv[])
{
	t_map	*map;

	if (ac != 2)
		exit(1);
	map = parse_map(argv[1]);
	if (!is_valid_map(&map))
	{
		free_map(&map);
		exit(1);
	}
	play_bonus(&map);
	return (0);
}
