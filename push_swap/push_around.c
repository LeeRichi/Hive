/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:29:08 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:39:51 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_node_to_a_top(t_list **stack, t_list *cheapest_node)
{
	int	len;
	int	r_len;

	len = stack_len(*stack);
	r_len = len - cheapest_node->index;
	if (*stack == cheapest_node)
		return ;
	if (cheapest_node->above_mid)
	{
		while (cheapest_node->index--)
			ra(stack, 1);
	}
	else
	{
		while (r_len--)
			rra(stack, 1);
	}
}

static void	bring_node_to_b_top(t_list **stack, t_list *cheapest_node)
{
	int	len;
	int	r_len;

	len = stack_len(*stack);
	if (*stack == cheapest_node->target_node)
		return ;
	if (cheapest_node->target_node->above_mid)
	{
		while (cheapest_node->target_node->index--)
			rb(stack, 1);
	}
	else
	{
		r_len = len - cheapest_node->target_node->index;
		while (r_len--)
			rrb(stack, 1);
	}
}

static void	fetch_target_for_pushing_b_nodes(t_list **stack, t_list *node)
{
	int	a_len;
	int	for_loop_poppose;

	a_len = stack_len(*stack);
	for_loop_poppose = a_len - node->target_node->index;
	if (node->target_node->above_mid)
	{
		while (node->target_node->index--)
			ra(stack, 1);
	}
	else
	{
		while (for_loop_poppose--)
			rra(stack, 1);
	}
}

void	from_a_to_b(t_list **a, t_list **b)
{
	bool	a_above_mid;
	bool	b_above_mid;
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	a_above_mid = cheapest_node->above_mid;
	b_above_mid = cheapest_node->target_node->above_mid;
	if (a_above_mid && b_above_mid)
	{
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rr(a, b);
	}
	else if (!a_above_mid && !b_above_mid)
	{
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rrr(a, b);
	}
	current_index(*a);
	current_index(*b);
	bring_node_to_a_top(a, cheapest_node);
	bring_node_to_b_top(b, cheapest_node);
	pb(a, b);
}

void	from_b_to_a(t_list **a, t_list **b)
{
	fetch_target_for_pushing_b_nodes(a, *b);
	pa(a, b);
}
