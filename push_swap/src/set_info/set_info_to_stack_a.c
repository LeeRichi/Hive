/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_to_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:58:09 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/19 14:56:46 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_target_node(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*target_node;
	long	best_matching;

	while (a)
	{
		best_matching = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->nbr < a->nbr && current->nbr > best_matching)
			{
				best_matching = current->nbr;
				target_node = current;
			}
			current = current->next;
		}
		if (best_matching == LONG_MIN)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	count_cost_helper(t_list *a, int len_a, int len_b)
{
	if (!(a->above_mid) && !(a->target_node->above_mid))
	{
		if (len_a - (a->index) > len_b - a->target_node->index)
			a->op_cost -= len_b - a->target_node->index;
		else
			a->op_cost -= len_a - a->index;
	}
	else if ((a->above_mid) && (a->target_node->above_mid))
	{
		if (a->index > a->target_node->index)
			a->op_cost -= a->target_node->index;
		else
			a->op_cost -= a->index;
	}
}

static void	count_cost(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->op_cost = a->index;
		if (!(a->above_mid))
			a->op_cost = len_a - (a->index);
		if (a->target_node->above_mid)
			a->op_cost += a->target_node->index;
		else
			a->op_cost += (len_b - a->target_node->index);
		count_cost_helper(a, len_a, len_b);
		a = a->next;
	}
}

static void	set_cheapest(t_list *stack)
{
	long	cheapest;
	t_list	*cheapest_node;

	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->op_cost < cheapest)
		{
			cheapest_node = stack;
			cheapest = stack->op_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	set_info_to_stack_a(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	count_cost(a, b);
	set_cheapest(a);
}
