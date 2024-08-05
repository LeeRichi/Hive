/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LEECHI <LEECHI@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:06:51 by LEECHI            #+#    #+#             */
/*   Updated: 2024/08/05 10:11:32 by LEECHI           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_sorted(t_list *stack)
{
	if(!stack || !stack->next)
		return (1);

	while(stack->next)
	{
		if(stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_list *find_min_node(t_list *stack)
{
	if(!stack)
		return (NULL);

	t_list *min_node;
	long min;

	min = LONG_MAX;
	while(stack)
	{
		if(stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}

		stack = stack->next;
	}
	return (min_node);
}

t_list *find_max_node(t_list *stack)
{
	if(!stack)
		return (NULL);

	long max;
	t_list *node_that_holds_max;

	max = LONG_MIN;
	while(stack)
	{
		if(stack->nbr > max)
		{
			max = stack->nbr;
			node_that_holds_max = stack;
		}
		stack = stack->next;
	}
	return(node_that_holds_max);
}

t_list *get_cheapest(t_list *stack)
{
	while(stack)
	{
		if(stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
