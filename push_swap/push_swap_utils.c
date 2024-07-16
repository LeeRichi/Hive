#include "push_swap.h"

static void swap_list(t_list *a, t_list *b)
{
	int temp;

	if(a && b)
	{
		temp = a->nbr;
		a->nbr = b->nbr;
		b->nbr = temp;
	}
}

void push(t_list **x, t_list **y)
{
	t_list *temp;

	if(x && *x)
	{
		temp = *x;
		*x = (*x)->next;
		temp->next = *y;
		*y = temp;
	}
}

void rotate(t_list **lst)
{
	t_list *temp;
	t_list *current;

	if(*lst && (*lst)->next)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = NULL;

		current = *lst;
		while(current->next)
			current = current->next;
		current->next = temp;
	}
}

void reverse_rotate(t_list **lst)
{
	t_list *temp;
	t_list *current;

	if(*lst && (*lst)->next)
	{
		current = *lst;
		while(current->next->next) //to the second next
			current = current->next;

		temp = current->next;
		current->next = NULL;

		temp->next = *lst;
		*lst = temp;
	}
}

void sa(t_list **stack_a)
{
	if(stack_a && *stack_a && (*stack_a)->next)
		swap_list(*stack_a, (*stack_a)->next);
}

void sb(t_list **stack_b)
{
	if(stack_b && *stack_b && (*stack_b)->next)
		swap_list(*stack_b, (*stack_b)->next);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(t_list **stack_a, t_list **stack_b)
{
	if(stack_b && *stack_b)
	{
		push(stack_b, stack_a);
	}
}

void pb(t_list **stack_a, t_list **stack_b)
{
	if(stack_a && *stack_a)
	{
		push(stack_a, stack_b);
	}
}

void ra(t_list **stack_a)
{
	rotate(stack_a);
}

void rb(t_list **stack_b)
{
	rotate(stack_b);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
}

void rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
