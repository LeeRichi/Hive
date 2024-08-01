#include "push_swap.h"
#include <stdio.h>

//this function set indexes for each node and set either true/false to above_mid
void current_index(t_list *a)
{
	int i;
	int mid;

	mid = stack_len(a) / 2;
	i = 0;
	while(a)
	{
		a->index = i;
		if(i <= mid)
			a->above_mid = true;
		else if(i > mid)
			a->above_mid = false;
		i++;
		a = a->next;
	}
}

// void set_target_node(t_list *a, t_list *b) //set each a
// {
// 	t_list *current;
// 	t_list *target_node;
// 	long best_matching;

// 	while(a)
// 	{
// 		best_matching = LONG_MIN;
// 		current = b;
// 		while(current)
// 		{
// 			if(current->nbr < a->nbr && current->nbr > best_matching) //cloest biggest value
// 			{
// 				best_matching = current->nbr; //best_matching being updated
// 				target_node = current;
// 			}
// 			current = current->next;
// 		}
// 		if(best_matching == LONG_MIN) //no matches found
// 			a->target_node = find_max_node(b);
// 		else
// 			a->target_node = target_node;
// 		// printf("test: %d\n", a->target_node->nbr);
// 		a = a->next;
// 	}
// }

// static void count_cost(t_list *a, t_list *b)
// {
// 	int len_a;
// 	int len_b;

// 	len_a = stack_len(a);
// 	len_b = stack_len(b);
// 	while(a)
// 	{
// 		a->op_cost = a->index;
// 		if(!(a->above_mid))
// 			a->op_cost = len_a - a->index;
// 		if(a->target_node->above_mid)
// 			a->op_cost += a->target_node->index;
// 		else
// 			a->op_cost += (len_b - a->target_node->index);
// 		a = a->next;
// 	}
// }

// static void set_cheapest(t_list *stack)
// {
// 	long cheapest;
// 	t_list *cheapest_node;

// 	cheapest = LONG_MAX;

// 	while(stack)
// 	{
// 		if(stack->op_cost < cheapest)
// 		{
// 			cheapest_node = stack;
// 			cheapest = stack->op_cost;
// 		}
// 		stack = stack->next;
// 	}
// 	cheapest_node->cheapest = true;
// }

// void set_info_to_stack_a(t_list *a, t_list *b)
// {
// 	current_index(a);
// 	current_index(b);
// 	set_target_node(a, b);
// 	count_cost(a, b);
// 	set_cheapest(a);
// }

void sort_stack(t_list **a, t_list **b)
{
	int len_a;

	len_a = stack_len(*a);

	printf("len_a is init %d\n", len_a);

	if(len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	if(len_a-- > 3 && !is_sorted(*a))
		pb(a, b);

	printf("len_a in mid is: %d\n", len_a);

	// printf("printing stack_a\n");
	// print_stack(*a);
	// printf("printing stack_b\n");
	// print_stack(*b);

	while(len_a-- > 3 && !is_sorted(*a))
	{
		printf("I want to know the len: %d\n", len_a);
		set_info_to_stack_a(*a, *b);
		from_a_to_b(a, b);

		printf("printing stack_a\n");
		print_stack(*a);
		printf("printing stack_b\n");
		print_stack(*b);
	}
	sort_three(a);
	while(*b)
	{
		set_info_to_stack_b(*a, *b);
		from_b_to_a(a, b);
	}
	current_index(*a);
	//a checker?
	//min_on_top();
}
