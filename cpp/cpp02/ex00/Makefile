NAME = ex00

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
# compiler generates dependency files:
# -MMD
# Generate dependencies for #include files, excluding system headers (like <iostream>), and write them to a .d file.

# -MP
# Add phony targets for each header file listed in the .d file.
DEPFLAGS = -MMD -MP

OBJDIR = obj
DEPDIR = dep

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEPDIR)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compile source files into obj/ and generate dep/
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPFLAGS) -MF $(DEPDIR)/$*.d

# Include dependency files
-include $(DEPS)

clean:
	$(RM) -r $(OBJDIR) $(DEPDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
