NAME = exeme

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++11

DEPFLAGS = -MMD -MP

OBJDIR = obj
DEPDIR = dep

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEPDIR)/%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPFLAGS) -MF $(DEPDIR)/$*.d

-include $(DEPS)

clean:
	$(RM) -r $(OBJDIR) $(DEPDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re





