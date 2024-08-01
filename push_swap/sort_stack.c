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

void min_on_top(t_list **stack)
{
	t_list *min_node;

	min_node = find_min_node(*stack);
	while(*stack != min_node)
	{
		if(min_node->above_mid)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

void sort_stack(t_list **a, t_list **b)
{
	int len_a;

	len_a = stack_len(*a);

	//printf("len_a is init %d\n", len_a);

	if(len_a > 3 && !is_sorted(*a))
	{
		pb(a, b);
		len_a--;
	}
	if(len_a > 3 && !is_sorted(*a))
	{
		pb(a, b);
		len_a--;
	}
	//printf("len_a in mid is: %d\n", len_a);

	// printf("printing stack_a\n");
	// print_stack(*a);
	// printf("printing stack_b\n");
	// print_stack(*b);

	while(len_a > 3 && !is_sorted(*a))
	{
		//printf("I want to know the len: %d\n", len_a);
		set_info_to_stack_a(*a, *b);
		from_a_to_b(a, b);

		//printf("printing stack_a\n");
		//print_stack(*a);
		//printf("printing stack_b\n");
		//print_stack(*b);
		len_a--;
	}
	//printf("tell me len_a: %d\n", len_a);
	if(len_a == 3 && !is_sorted(*a))
	{
		sort_three(a);
		//printf("is this ever triggered?");
	}
	while(*b)
	{
		set_info_to_stack_b(*a, *b);
		from_b_to_a(a, b);
	}
	current_index(*a);
	//a checker?
	min_on_top(a);
}
