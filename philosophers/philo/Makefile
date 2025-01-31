# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:27:00 by chlee2            #+#    #+#              #
#    Updated: 2025/01/30 22:49:16 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# LIBFTDIR = lib/libft
# LIBFT = $(LIBFTDIR)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# not sure if -lncureses in needed?
# LDFLAGS = -L$(LIBFTDIR) -lft -lreadline -lncurses

SRCS = src/main.c \
				src/helpers.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# $(LIBFT):
# 	@make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	@make clean -C

fclean: clean
	rm -f $(NAME)
	@make fclean -C

re: fclean $(NAME)

.PHONY: all clean fclean re


