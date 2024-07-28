#include "push_swap.h"

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

void bring_node_to_top(t_list **stack, t_list *cheapest_node, char name)
{
	int len;
	int r_len;

	len = stack_len(*stack);
	r_len = (*stack)->index - len;
	if(name == 'a')
	{
		if(cheapest_node->above_mid)
		{
			while(len--)
				ra(stack);
		}
		else
		{
			while(len--)
				rra(stack);
		}
	}
	else if(name == 'b')
	{
		if(cheapest_node->target_node->above_mid)
		{
			while(r_len--)
				rb(stack);
		}
		else
		{
			while(r_len--)
				rb(stack);
		}
	}
}

void from_a_to_b(t_list **a, t_list **b)
{
	t_list *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if(cheapest_node->above_mid && cheapest_node->target_node->above_mid)
		rr(a, b);
	else if (!(cheapest_node->above_mid) && !(cheapest_node->target_node->above_mid))
		rrr(a, b);
	bring_node_to_top(a, cheapest_node, 'a');
	bring_node_to_top(b, cheapest_node, 'b');
	pa(a, b);
}
