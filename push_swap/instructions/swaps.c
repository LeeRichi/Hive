/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:29:16 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/05 18:03:43 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack_a, int print)
{
	if (stack_a && *stack_a && (*stack_a)->next)
		swap_list(*stack_a, (*stack_a)->next);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, int print)
{
	if (stack_b && *stack_b && (*stack_b)->next)
		swap_list(*stack_b, (*stack_b)->next);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
