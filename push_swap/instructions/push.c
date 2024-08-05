/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:52:26 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/05 17:52:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_list **stack_a, t_list **stack_b)
{
	if(stack_b && *stack_b)
	{
		push(stack_b, stack_a);
	}
	ft_printf("pa\n");
}

void pb(t_list **stack_a, t_list **stack_b)
{
	if(stack_a && *stack_a)
	{
		push(stack_a, stack_b);
	}
	ft_printf("pb\n");
}
