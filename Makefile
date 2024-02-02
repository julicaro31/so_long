# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaro <jcaro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:10:20 by jcaro             #+#    #+#              #
#    Updated: 2023/12/13 23:57:45 by jcaro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLX = mlx
LIBFT = libft.a
SRCS =	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_type.c \
		ft_printf/ft_printf_s.c \
		ft_printf/ft_printf_p.c \
		ft_printf/ft_printf_di.c \
		ft_printf/ft_printf_u.c \
		ft_printf/ft_printf_x.c \
		map/draw_map.c \
		map/draw_line.c \
		map/free_images.c \
		map/parse_map.c \
		map/map_utils.c \
		map/map_checkers.c \
		map/map_checkers_utils.c \
		map/valid_path.c \
		map/valid_path_utils.c \
		game/play.c \
		game/open_images.c \
		game/clean_exit.c \
		game/handle_input.c \
		game/init_game.c \
		game/updates.c \
		game/game_utils.c \
		game/partial_rendering.c

SRCS_BONUS = 	main_bonus.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_printf_type.c \
				ft_printf/ft_printf_s.c \
				ft_printf/ft_printf_p.c \
				ft_printf/ft_printf_di.c \
				ft_printf/ft_printf_u.c \
				ft_printf/ft_printf_x.c \
				map/draw_map_bonus.c \
				map/draw_line_bonus.c \
				map/free_images.c \
				map/parse_map.c \
				map/map_utils.c \
				map/map_checkers.c \
				map/map_checkers_utils.c \
				map/valid_path.c \
				map/valid_path_utils.c \
				game/play_bonus.c \
				game/open_images.c \
				game/clean_exit.c \
				game/handle_input_bonus.c \
				game/init_game.c \
				game/updates.c \
				game/game_utils.c \
				game/check_enemy.c \
				game/partial_rendering_bonus.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
FLAGS = -Wall -Wextra -Werror
CC = cc

%.o: %.c
	$(CC) $(FLAGS) -Iinclude -I/usr/include -Imlx_linux -c $< -o $@

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -Llibft -lft -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	make -C libft -f Makefile

$(MLX):
	cd mlx_linux; bash configure

bonus: $(MLX) $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -Lmlx_linux -lmlx_Linux -Llibft -lft -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C mlx_linux
	make clean -C libft -f Makefile

fclean: clean
	rm -f $(NAME)
	make fclean -C libft -f Makefile

re: fclean all

.PHONY: all clean fclean re