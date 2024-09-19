# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by chlee2            #+#    #+#              #
#    Updated: 2024/09/19 14:58:16 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEBONUS = checker

LIBFT = libft.a
LIBFTDIR = libft

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS = src/main.c \
		src/init_stack.c \
		src/init_stack_by_string.c \
		src/node_operation.c \
		src/stack_utils.c \
		src/sort_stack.c \
		src/push_around.c \
		src/set_info/set_info_to_stack_a.c \
		src/set_info/set_info_to_stack_b.c \
		src/ps_split.c \
		src/general_functions/std_error.c \
		src/general_functions/free_things.c \
		src/instructions/index.c \
		src/instructions/swaps.c \
		src/instructions/rotations.c \
		src/instructions/reverse_rotations.c \
		src/instructions/push.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/main_bonus.c \
				src/init_stack.c \
				src/init_stack_by_string.c \
				src/node_operation.c \
				src/stack_utils.c \
				src/sort_stack.c \
				src/push_around.c \
				src/set_info/set_info_to_stack_a.c \
				src/set_info/set_info_to_stack_b.c \
				src/ps_split.c \
				src/general_functions/std_error.c \
				src/general_functions/free_things.c \
				src/instructions/index.c \
				src/instructions/swaps.c \
				src/instructions/rotations.c \
				src/instructions/reverse_rotations.c \
				src/instructions/push.c \

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(NAMEBONUS)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(NAMEBONUS): $(BONUS_OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAMEBONUS) $(BONUS_OBJS) -L$(LIBFTDIR) -lft

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)
	@make fclean -C $(LIBFTDIR)

re: fclean $(NAME) $(NAMEBONUS)

.PHONY: all clean fclean re
