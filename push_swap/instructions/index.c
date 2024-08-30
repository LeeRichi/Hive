/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:30:32 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:40:23 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_list(t_list *a, t_list *b)
{
	int	temp;

	if (a && b)
	{
		temp = a->nbr;
		a->nbr = b->nbr;
		b->nbr = temp;
	}
}

void	push(t_list **x, t_list **y)
{
	t_list	*temp;

	if (x && *x)
	{
		temp = *x;
		*x = (*x)->next;
		temp->next = *y;
		*y = temp;
	}
}

void	rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (*lst && (*lst)->next)
	{
		temp = *lst;
		*lst = (*lst)->next;
		temp->next = NULL;
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = temp;
	}
}

void	reverse_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (*lst && (*lst)->next)
	{
		current = *lst;
		while (current->next->next)
			current = current->next;
		temp = current->next;
		current->next = NULL;
		temp->next = *lst;
		*lst = temp;
	}
}
