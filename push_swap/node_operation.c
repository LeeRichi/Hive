#include "push_swap.h"

t_list *new_node(int value)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	if(!node)
		return (NULL);
	node->nbr = value;
	node->next = NULL;
	return (node);
}

void push_single_stack(t_list **stack, int value)
{
    t_list *node = new_node(value);
    if (node)
    {
        node->next = *stack;
        *stack = node;
    }
}

void pop_single_stack(t_list **stack)
{
	if(stack && *stack)
	{
		t_list *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
