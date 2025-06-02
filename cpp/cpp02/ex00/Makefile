# NAME = ex00

# CC = c++
# RM = rm -f
# CFLAGS = -Wall -Wextra -Werror -std=c++98
# DEPFLAGS = -MMD -MP

# SRCS = main.cpp Fixed.cpp

# OBJS = $(SRCS:.cpp=.o)

# DEPS = $(OBJS:.o=.d)

# all:$(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# %.o: %.cpp
# 	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# -include $(DEPS)

# clean:
# 	$(RM) $(OBJS) $(DEPS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


NAME = ex00

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
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
