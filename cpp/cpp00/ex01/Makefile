# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#              #
#    Updated: 2025/05/23 18:21:59 by chlee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

HEADER_FILES = PhoneBook.hpp Contact.hpp
SRC_FILES = main.cpp PhoneBook.cpp Contact.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++11
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
