#variables

NAME = libftprintf.a
LIBFT = libft.a
LIBFTDIR = libft
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


SRCS = ft_printf.c \
		ft_printlib.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re