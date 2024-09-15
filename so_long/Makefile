# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by chlee2            #+#    #+#              #
#    Updated: 2024/09/14 23:23:22 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTDIR = lib/libft
LIBFT = $(LIBFTDIR)/libft.a

MLX42DIR = lib/MLX42
MLX42 = $(MLX42DIR)/build/libmlx42.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
		src/window_init.c \
		src/delete.c \
		src/map_checker.c \
		src/img_init.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLX42DIR)/build -lmlx42 -lglfw

$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX42):
	@cmake -B $(MLX42DIR)/build -S $(MLX42DIR)
	@cmake --build $(MLX42DIR)/build

# clean:
# 	$(RM) $(OBJS)
# 	@make clean -C $(LIBFTDIR)
# 	@cmake --build $(MLX42DIR)/build --target clean

# fclean: clean
# 	rm -f $(NAME)
# 	@make fclean -C $(LIBFTDIR)
# 	$(RM) -r $(MLX42DIR)/build

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

# build_exec: $(OBJS) $(LIBFT)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re


