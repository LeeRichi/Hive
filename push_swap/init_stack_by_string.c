/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_by_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:18:21 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/18 17:23:47 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_args(t_list **stack, char **split_av)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack);
		*stack = (*stack)->next;
		free(temp);
	}
	ft_two_free_throws(split_av);
	std_error();
}

void	initialize_stack_by_string(t_list **stack, int ac, char **av)
{
	int	value;

	while (ac - 1 >= 0)
	{
		value = ft_atoi(av[ac - 1]);
		if (!ft_checker(av[ac - 1]) || is_dup(*stack, value))
			free_args(stack, av);
		push_single_stack(stack, value);
		ac--;
	}
}
