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
	//printf("min value in this stack is: %ld\n", min);
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
	//printf("max value in this stack is: %ld\n", max);
	return(node_that_holds_max);
}


void sort_three(t_list **stack)
{
	t_list *min_node;

	printf("sort_three triggered.\n");
	// printf("---\n");
	// print_stack(*stack);
	// printf("---\n");

	if(stack_len(*stack) != 3)
		return;

	min_node = find_min_node(*stack);
	// printf("first node value: %d\n", (*stack)->next->nbr);
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
