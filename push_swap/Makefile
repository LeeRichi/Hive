# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by chlee2            #+#    #+#              #
#    Updated: 2024/08/07 15:11:55 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap.a
NAME = push_swap

LIBFT = libft.a
LIBFTDIR = libft

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRCS = push_swap.c \
		node_operation.c \
		stack_utils.c \
		sort_stack.c \
		push_around.c \
		set_info/set_info_to_stack_a.c \
		set_info/set_info_to_stack_b.c \
		ps_split.c \
		general_functions/std_error.c \
		general_functions/free_things.c \
		instructions/index.c \
		instructions/swaps.c \
		instructions/rotations.c \
		instructions/reverse_rotations.c \
		instructions/push.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

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
