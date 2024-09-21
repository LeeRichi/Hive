/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:52:26 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/21 11:43:09 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int print)
{
	if (stack_b && *stack_b)
		push(stack_b, stack_a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	if (stack_a && *stack_a)
		push(stack_a, stack_b);
	if (print)
		ft_printf("pb\n");
}
