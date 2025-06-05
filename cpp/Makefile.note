
NAME = DiamondTrap

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++17

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

all:$(NAME)

# notes
# $@ target
# $@ = target name → expands to $(NAME) (i.e., DiamondTrap)

# $< first prerequisite
# $< = first dependency → the .cpp file

# $^ all prerequisites (all .o files)
# $^ = all dependencies → expands to $(OBJS) (i.e., all the .o files)

# -c flag tells the compiler to compile source files into object files without linking.

# This rule compiles .cpp source files into .o object files.
# eg: c++ -Wall -Wextra -Werror -std=c++17 -c main.cpp -o main.o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# This rule links object files into the final executable.
# eg. c++ -Wall -Wextra -Werror -std=c++17 -c main.cpp -o main.o
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


