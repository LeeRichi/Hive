# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#              #
#    Updated: 2025/05/22 12:57:22 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dreamjob

HEADER_FILES = Account.hpp
SRC_FILES = tests.cpp Account.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
DEPENDENCIES = $(HEADER_FILES) Makefile

all: $(NAME)

%.o: %.cpp $(DEPENDENCIES)
	$(CPP) $(CPP_FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CPP) $(CPP_FLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
