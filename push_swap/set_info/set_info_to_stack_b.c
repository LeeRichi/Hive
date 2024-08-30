/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info_to_stack_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:56:37 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:40:19 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//set each b //closest bigger
static void	set_target_node_version_b(t_list *a, t_list *b)
{
	long	best_value;
	t_list	*target_node;
	t_list	*current;

	while (b)
	{
		best_value = LONG_MAX;
		current = a;
		while (current)
		{
			if (b->nbr < current->nbr && best_value > current->nbr)
			{
				target_node = current;
				best_value = current->nbr;
			}
			current = current->next;
		}
		if (best_value == LONG_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_info_to_stack_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_node_version_b(a, b);
}
