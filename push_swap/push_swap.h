#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_list
{
	int			nbr;
	int			min;
	int			index;
	int			op_cost;
	bool		cheapest;
	bool		above_mid;
	struct s_list	*next;
	struct s_list	*target_node;
}	t_list;

//push_swap.c //main
int is_dup(t_list *stack, int value);
int ft_checker(char *str);
void initialize_stack(t_list **stack, int ac, char **av);
void push_swap(t_list **a_stack, t_list **b_stack);

//node_operation.c
int stack_len(t_list *stack);
t_list *new_node(int value);
void push_single_stack(t_list **stack, int value);
void pop_single_stack(t_list **stack);

//push_swap_utils.c
// static void swap_list(t_list *a, t_list *b);
void push(t_list **x, t_list **y);
void rotate(t_list **lst);
void reverse_rotate(t_list **lst);

void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);

//stack_utils.c
bool is_sorted(t_list *stack);
t_list *find_min_node(t_list *stack);
t_list *find_max_node(t_list *stack);
void sort_three(t_list **stack);

//sort_stack.c
void sort_stack(t_list **a, t_list **b);
void set_target_node(t_list *a, t_list *b);



void print_stack(t_list *stack);

#endif
