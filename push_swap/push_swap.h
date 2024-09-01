/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:41:24 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/01 17:15:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				nbr;
	int				min;
	int				index;
	int				op_cost;
	bool			cheapest;
	bool			above_mid;
	struct s_list	*next;
	struct s_list	*target_node;
}	t_list;

//push_swap.c //main
// int		is_dup(t_list *stack, int value);
// int		ft_checker(char *str);
// void	initialize_stack(t_list **stack, int ac, char **av);

//ps_split.c
int		str_len(char *str);
char	**ps_split(char *str, int *am_words);

//node_operation.c
int		stack_len(t_list *stack);
void	push_single_stack(t_list **stack, int value);

//general_functions
void	std_error(void);
void	ft_free_throw(t_list *stack);
void	ft_two_free_throws(char **stack);

//instructions.c
void	swap_list(t_list *a, t_list *b);
void	push(t_list **x, t_list **y);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);

void	sa(t_list **stack_a, int print);
void	sb(t_list **stack_b, int print);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b);

//stack_utils.c
bool	is_sorted(t_list *stack);
t_list	*find_min_node(t_list *stack);
t_list	*find_max_node(t_list *stack);
t_list	*get_cheapest(t_list *stack);

//set_info
//set_info_to_stack_a
void	set_info_to_stack_a(t_list *a, t_list *b);
//set_info_to_stack_b
void	set_info_to_stack_b(t_list *a, t_list *b);

//sort_stack.c
void	current_index(t_list *a);
void	sort_three(t_list **stack);
void	sort_stack(t_list **a, t_list **b);

//push_around
void	from_a_to_b(t_list **a, t_list **b);
void	from_b_to_a(t_list **a, t_list **b);

//temp
void	print_stack(t_list *stack);

#endif
