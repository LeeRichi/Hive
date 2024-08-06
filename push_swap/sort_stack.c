/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:39:31 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/05 17:42:48 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function set indexes for each node and set either true/false to above_mid
void	current_index(t_list *a)
{
	int	i;
	int	mid;

	mid = stack_len(a) / 2;
	i = 0;
	while (a)
	{
		a->index = i;
		if (i <= mid)
			a->above_mid = true;
		else if (i > mid)
			a->above_mid = false;
		i++;
		a = a->next;
	}
}

static void	min_on_top(t_list **stack)
{
	t_list	*min_node;

	min_node = find_min_node(*stack);
	while (*stack != min_node)
	{
		if (min_node->above_mid)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

//for the sake of 'more than 25 lines'
static void	sake_of_25(t_list **stack)
{
	rra(stack, 1);
	sa(stack, 1);
}

void	sort_three(t_list **stack)
{
	t_list	*min_node;

	min_node = find_min_node(*stack);
	if ((*stack)->nbr == min_node->nbr)
	{
		if ((*stack)->next->nbr > (*stack)->next->next->nbr)
			sake_of_25(stack);
	}
	else if ((*stack)->next->nbr == min_node->nbr)
	{
		if ((*stack)->nbr > (*stack)->next->next->nbr)
			ra(stack, 1);
		else
			sa(stack, 1);
	}
	else if ((*stack)->next->next->nbr == min_node->nbr)
	{
		if ((*stack)->nbr > (*stack)->next->nbr)
			sake_of_25(stack);
		else
			rra(stack, 1);
	}
}

void	sort_stack(t_list **a, t_list **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a > 3 && !is_sorted(*a))
	{
		pb(a, b);
		len_a--;
	}
	while (len_a > 3 && !is_sorted(*a))
	{
		set_info_to_stack_a(*a, *b);
		from_a_to_b(a, b);
		len_a--;
	}
	if (len_a == 3 && !is_sorted(*a))
		sort_three(a);
	while (*b)
	{
		set_info_to_stack_b(*a, *b);
		from_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
