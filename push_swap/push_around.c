/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_around.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LEECHI <LEECHI@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:29:08 by LEECHI            #+#    #+#             */
/*   Updated: 2024/08/05 09:32:23 by LEECHI           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list *get_cheapest(t_list *stack)
{
	while(stack)
	{
		if(stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void bring_node_to_top(t_list **stack, t_list *cheapest_node, char name)
{
	int len;
	int r_len;

	len = stack_len(*stack);
	if(name == 'a')
	{
		r_len = len - cheapest_node->index;
		if(*stack == cheapest_node)
			return;
		if(cheapest_node->above_mid)
		{
			while(cheapest_node->index--)
				ra(stack, 1);
		}
		else
		{
			while(r_len--)
				rra(stack, 1);
		}
	}
	else if(name == 'b')
	{
		if(*stack == cheapest_node->target_node)
			return;
		if(cheapest_node->target_node->above_mid)
		{
			while(cheapest_node->target_node->index--)
				rb(stack, 1);
		}
		else
		{
			r_len = len - cheapest_node->target_node->index;
			while(r_len--)
				rrb(stack, 1);
		}
	}
}

static void fetch_target_for_pushing_b_nodes(t_list **stack, t_list *node)
{
	int a_len;
	int for_loop_poppose;

	a_len = stack_len(*stack);
	for_loop_poppose = a_len - node->target_node->index;

	if(node->target_node->above_mid)
	{
		while(node->target_node->index--)
			ra(stack, 1);
	}
	else
	{
		while(for_loop_poppose--)
			rra(stack, 1);
	}
}

void from_a_to_b(t_list **a, t_list **b)
{
	t_list *cheapest_node;
	cheapest_node = get_cheapest(*a);

	//the situation that we can use double rotate instead of single rotate.
	if(*a != cheapest_node && *b != cheapest_node->target_node) //but one case we have to avoid is that when the node is on top already.
	{
		if(cheapest_node->above_mid && cheapest_node->target_node->above_mid)
			rr(a, b);
		else if (!(cheapest_node->above_mid) && !(cheapest_node->target_node->above_mid))
			rrr(a, b);
	}
	current_index(*a);
	current_index(*b);
	bring_node_to_top(a, cheapest_node, 'a');
	bring_node_to_top(b, cheapest_node, 'b');
	pb(a, b);
}
void from_b_to_a(t_list **a, t_list **b)
{
	fetch_target_for_pushing_b_nodes(a, *b);
	pa(a, b);
}
