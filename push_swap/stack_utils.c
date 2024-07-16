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
	printf("min value in this stack is: %ld\n", min);
	return (min_node);
}

void sort_three(t_list **stack)
{
	t_list *min_node;

	min_node = find_min_node(*stack);
	if((*stack)->nbr == min_node->nbr) //min_node on top
	{
		if((*stack)->next->nbr > (*stack)->next->next->nbr)
		{
			reverse_rotate(stack);
			sa(stack);
		}
	}
	else if((*stack)->next->nbr == min_node->nbr)
	{
		if((*stack)->nbr > (*stack)->next->next->nbr)
			rotate(stack);
		else
			sa(stack);
	}
	else if((*stack)->next->next->nbr == min_node->nbr)
	{
		if((*stack)->nbr > (*stack)->next->nbr)
		{
			sa(stack);
			reverse_rotate(stack);
		}
		else
			reverse_rotate(stack);
	}
}
