/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:31:06 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/19 14:56:56 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_list **stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, int print)
{
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
