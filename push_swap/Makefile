# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: LEECHI <LEECHI@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by LEECHI            #+#    #+#              #
#    Updated: 2024/07/11 13:57:00 by LEECHI           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap.a
NAME = push_swap

LIBFT = libft.a
LIBFTDIR = libft

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
		node_operation.c \
		push_swap_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# $(NAME): $(OBJS)
# 	@make -C $(LIBFTDIR)
# 	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
# 	ar rcs $(NAME) $(OBJS)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re