/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:31:13 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/05 17:41:23 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_list **stack_a, int print)
{
	reverse_rotate(stack_a);
	if(print)
		ft_printf("rra\n");
}

void rrb(t_list **stack_b, int print)
{
	reverse_rotate(stack_b);
	if(print)
		ft_printf("rrb\n");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}
