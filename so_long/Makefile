# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by chlee2            #+#    #+#              #
#    Updated: 2024/10/09 16:56:27 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTDIR = lib/libft
LIBFT = $(LIBFTDIR)/libft.a

MLX42DIR = lib/MLX42
MLX42 = $(MLX42DIR)/build/libmlx42.a
MLX42_REPO = https://github.com/codam-coding-college/MLX42.git

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src/main.c \
		src/window_init.c \
		src/window_init_helpers.c \
		src/valid_movements.c \
		src/delete.c \
		src/flood_packs.c \
		src/map_checker.c \
		src/img_init.c \
		src/deep_copy.c \
		src/init_map.c \
		src/draw_ground.c \
		src/draw_camera.c \
		src/win_exit.c \
		src/check_block.c \

OBJS = $(SRCS:.c=.o)

all: $(MLX42DIR) $(NAME)

$(MLX42DIR):
	git clone $(MLX42_REPO) $(MLX42DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLX42DIR)/build -lmlx42 -lglfw

$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX42):
	@cmake -B $(MLX42DIR)/build -S $(MLX42DIR)
	@cmake --build $(MLX42DIR)/build

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFTDIR)
	rm -rf $(MLX42DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re


