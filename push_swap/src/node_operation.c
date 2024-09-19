/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:54:20 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/19 14:56:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_list *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

static t_list	*new_node(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nbr = value;
	node->next = NULL;
	return (node);
}

void	push_single_stack(t_list **stack, int value)
{
	t_list	*node;

	node = new_node(value);
	if (node)
	{
		node->next = *stack;
		*stack = node;
	}
}
