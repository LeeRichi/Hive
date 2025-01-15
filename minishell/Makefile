# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 14:27:00 by chlee2            #+#    #+#              #
#    Updated: 2025/01/15 14:08:39 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTDIR = lib/libft
LIBFT = $(LIBFTDIR)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# not sure if -lncureses in needed?
# LDFLAGS = -L$(LIBFTDIR) -lft -lreadline -lncurses
LDFLAGS = -L$(LIBFTDIR) -lft -lreadline
SRCS = src/main.c \
		src/parse.c \
		src/sig.c \
		src/buildins/echo.c \
		src/buildins/cd.c \
		src/buildins/pwd.c \
		src/buildins/exit.c \
		src/lex/lex.c \
		src/lex/wrong_pipe.c \
		src/utils/free.c \
		src/utils/print.c \
		src/lex/quotes_and_dollar.c \
		src/lex/lex_helper.c \
		src/lex/heredoc.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) $(LDFLAGS)

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean $(NAME)

.PHONY: all clean fclean re


