#include "push_swap.h"


//temp
static void	rotate_both(t_list **a, t_list **b,	t_list *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node, and the current top `a` node is not the top node
		rr(a, b); //Rotate both `a` and `b` nodes
	current_index(*a);
	current_index(*b);
}

// static void	rev_rotate_both(t_list **a, t_list **b,	t_list *cheapest_node) //Define a function that rotates both the bottom `a` and `b` nodes to the top of their stacks, if it's the cheapest move
// {
// 	while (*b != cheapest_node->target_node
// 		&& *a != cheapest_node) //As long as the current `b` node is not `a` cheapest node's target node && and the current `a` node is not the cheapest
// 		rrr(a, b); //Reverse rotate both `a` and `b` nodes
// 	current_index(*a); //Refresh current node positions
// 	current_index(*b);
// }
//temp end

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

// static int top_checker(t_list **a, t_list **b, t_list *cheapest_node)
// {
// 	while(*a != cheapest_node && *b != cheapest_node->target_node)
// 		return (0);
// 	// current_index(*a);
// 	// current_index(*b);
// 	return (1);
// }

void from_a_to_b(t_list **a, t_list **b)
{
	t_list *cheapest_node;
	cheapest_node = get_cheapest(*a);

	// ft_printf("cheapest_node's value: %d\n", cheapest_node->nbr);
	// ft_printf("and it takes %d steps\n", cheapest_node->op_cost);

	//the situation that we can use double rotate instead of single rotate.
	// if(top_checker(a, b, cheapest_node) == 0) //but one case we have to avoid is that when the node is on top already.
	// while(top_checker(a, b, cheapest_node) != 0)
	// {
		if(cheapest_node->above_mid && cheapest_node->target_node->above_mid)
			rotate_both(a, b, cheapest_node);
		else if (!(cheapest_node->above_mid) && !(cheapest_node->target_node->above_mid))
			rrr(a, b);
	// }
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
