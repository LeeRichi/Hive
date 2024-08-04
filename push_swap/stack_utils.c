#include "push_swap.h"

#include <stdio.h> //temp

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

void sort_three(t_list **stack)
{
	t_list *min_node;

	if(stack_len(*stack) != 3)
		return;

	min_node = find_min_node(*stack);
	if((*stack)->nbr == min_node->nbr) //min_node on top
	{
		if((*stack)->next->nbr > (*stack)->next->next->nbr)
		{
			rra(stack, 1);
			// reverse_rotate(stack);
			sa(stack, 1);
		}
	}
	else if((*stack)->next->nbr == min_node->nbr)
	{
		if((*stack)->nbr > (*stack)->next->next->nbr)
			ra(stack, 1);
		else
			sa(stack, 1);
	}
	else if((*stack)->next->next->nbr == min_node->nbr)
	{
		if((*stack)->nbr > (*stack)->next->nbr)
		{
			sa(stack, 1);
			// reverse_rotate(stack);
			rra(stack, 1);
		}
		else
			// reverse_rotate(stack);
			rra(stack, 1);
	}
}
