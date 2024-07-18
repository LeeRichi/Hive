#include "push_swap.h"

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

void set_target_node(t_list *a, t_list *b)
{
	
}

void set_info_to_stack_a(t_list *a)
{
	current_index(a);
	current_index(b);
	set_target_node(a, b);
	count_cost(a, b);
	set_cheapest(a);
}

void sort_stack(t_list **a, t_list **b)
{
	int len_a;

	len_a = stack_len(a);
	if(len_a-- > 3 && !is_sorted(a))
		pb(a, b);
	if(len_a-- > 3 && !is_sorted(a))
		pb(a, b);
	while(len_a-- > 3 && !is_sorted(a))
	{
		set_info_to_stack_a(*a, *b);
		from_a_to_b(*a, *b);
	}
	sort_three(a);
	//move nodes from b to a
	while(*b)
	{
		set_info_to_stack_b(*a, *b);
		from_b_to_a(*a, *b);
	}
	current_index(*a);
	//a checker?
	//min_on_top();
}
