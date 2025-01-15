NAME = libft.a

SRCS = ft_isalpha.c \
		ft_strlen.c \
		ft_memmove.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_isalnum.c \
		ft_strchr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_split.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		is_empty_or_whitespace.c \
		ft_realloc.c \
		ft_strncmp.c \
		ft_strtrim.c \

# BONUS = ft_lstmap_bonus.c ft_lstnew_bonus.c 			\
# 		ft_lstlast_bonus.c ft_lstsize_bonus.c			\
# 		ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c	\
# 		ft_lstdelone_bonus.c ft_lstclear_bonus.c		\
# 		ft_lstiter_bonus.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	@touch .bonus

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	@rm -rf .bonus

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_OBJS)

re: fclean $(NAME)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus

