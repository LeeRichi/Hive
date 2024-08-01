#include "../push_swap.h"

static void set_target_node_version_b(t_list *a, t_list *b) //set each b //closest bigger
{
	long best_value;
	t_list *target_node;
	t_list *current;

	while(b)
	{
		best_value = LONG_MAX;
		current = a;
		while(current)
		{
			if(b->nbr < current->nbr && best_value > current->nbr)
			{
				target_node = current;
				best_value = current->nbr;
			}
			current = current->next;
		}
		if(best_value == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

// static void count_cost_version_b(t_list *a, t_list *b)
// {
// 	int steps;
// 	int len_a;
// 	int len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while(b)
// 	{
// 		steps = b->index;
// 		if(!(b->above_mid))
// 			steps = len_b - (b->index);
// 		if(b->target_node->above_mid)
// 			steps += b->target_node->index;
// 		else
// 			steps += len_a - (b->target_node->index);
// 		b = b->next;
// 	}
// }

void set_info_to_stack_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_node_version_b(a, b);

	// ft_printf("b->nbr: test this shit: %d\n", b->nbr);
	// ft_printf("b->target_node->nbr: test this shit: %d\n", b->target_node->nbr); //should be 6
	// count_cost_version_b(a, b);
	// set_cheapest(b);
}
