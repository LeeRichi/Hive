#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_list
{
	int			nbr;
	int			min;
	struct s_list	*next;
}	t_list;

int is_dup(t_list *stack, int value);
int ft_checker(char *str);
void initialize_stack(t_list **stack, int ac, char **av);
void push_swap(t_list **a_stack, t_list **b_stack);
t_list *new_node(int value);
void push(t_list **x, t_list **y);

void push_single_stack(t_list **stack, int value);
void pop_single_stack(t_list **stack);

bool is_sorted(t_list *stack);
t_list *find_min_node(t_list *stack);
void sort_three(t_list **stack);

void rotate(t_list **lst);
void reverse_rotate(t_list **lst);
void sa(t_list **stack_a);

#endif
