NAME = pipex

SRCS = src/child_process.c \
	src/close.c \
	src/error.c \
	src/path_finder.c \
	src/tool.c \
	src/main.c \

LIBFTDIR = lib/libft
LIBFT = $(LIBFTDIR)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

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


