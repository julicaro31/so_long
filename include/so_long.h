/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:50:45 by jcaro             #+#    #+#             */
/*   Updated: 2023/12/14 00:07:43 by jcaro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# define IMG_SIZE 100
# define MAXCOL 38
# define MAXROW 20

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int				row;
	char			*line;
	struct s_map	*next;
	struct s_map	*prev;
	int				*check;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		x;
	int		y;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		wx;
	int		wy;
	int		nrow;
	int		ncol;
	int		moves;
	int		collect;
	t_map	**map;
	void	**img;
}	t_data;

void	draw_map(t_data *data);
void	draw_line(t_data *data, char *line, int row);
void	**open_images(t_data *data);
int		free_images(t_data *data);
t_map	*add_back(t_map **head, char *line, int row);
t_map	*free_map(t_map **head);
t_map	*parse_map(char *map_path);
int		is_valid_map(t_map **head);
int		check_side_wall(char *line);
int		check_first_last_wall(char *line);
int		valid_path(t_map **map);
int		valid_path_collectibles(t_map **map);
int		get_height(t_map **map);
int		get_width(t_map **map);
int		get_index(char c);
int		is_valid_character(char c);
int		find_character(char *line, char c);
t_map	*find_start(t_map **map, char c);
void	change_check_status(t_map **map, t_map *start, int col);
void	restore_status(t_map **map);
void	play(t_map **map);
void	clean_exit(t_map **map, t_data *data, int i);
int		handle_input(int keysym, t_data *data);
void	init_game(t_data *data, t_map **map);
void	display_img(t_data *data, void *img_ptr, int x, int y);
void	update_current_img(t_data *data, int x, int y);
void	update_new_img(t_data *data, int x, int y);
void	update_colectible(t_data *data);
void	update_exit(t_data *data);
void	update(t_data *data);
t_map	*find_row(t_map **map, int row);
int		possible_move(t_data *data, int x, int y);
int		is_character(t_data *data, int x, int y, char c);
void	check_if_finished(t_data *data);
int		exit_game(t_data *data);
void	play_bonus(t_map **map);
void	draw_map_bonus(t_data *data, int init);
void	draw_line_bonus(t_data *data, char *line, int row);
int		handle_input_bonus(int keysym, t_data *data);
void	check_enemy(t_data *data);
int		right_render(t_data *data);
int		left_render(t_data *data);
int		up_render(t_data *data);
int		down_render(t_data *data);

#endif