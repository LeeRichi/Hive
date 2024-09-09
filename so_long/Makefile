# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by chlee2            #+#    #+#              #
#    Updated: 2024/09/09 17:34:52 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTDIR = lib/libft
LIBFT = $(LIBFTDIR)/libft.a

MLXDIR = lib/minilibx_opengl
MLX = $(MLXDIR)/libmlx.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
		src/window_init.c \
		src/delete.c \
		src/map_checker.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# ??
# %.o: %.c
# 	@cc $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(MLXDIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean $(NAME)
.PHONY: all clean fclean re
