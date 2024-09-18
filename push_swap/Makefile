# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 18:30:28 by chlee2            #+#    #+#              #
#    Updated: 2024/09/18 13:42:36 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEBONUS = checker

LIBFT = libft.a
LIBFTDIR = libft

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

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

BONUS_SRCS = bonus/main_bonus.c \
				bonus/basic_check.c \
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

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(NAMEBONUS)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

# cc -Wall -Wextra -Werror -g3 -fsanitize=address your_program.c -o your_program


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

debug: CFLAGS += -fsanitize=address -g3
debug: re

.PHONY: all clean fclean re debug
