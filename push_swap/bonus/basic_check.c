/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:51:16 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/01 22:51:40 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	is_dup(t_list *stack, int value)
{
	while (stack)
	{
		if (stack->nbr == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

//if it's 0 or -1, that means overflow. //1 is pass
int	ft_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str_len(str) == 2 && (str[0] == '-' && str[1] == '1'))
		return (1);
	else if (str_len(str) == 1 && str[0] == '0')
		return (1);
	else if (ft_atoll(str) != 0 && ft_atoll(str) != -1)
		return (1);
	else
		return (0);
}

void	initialize_stack(t_list **stack, int ac, char **av)
{
	int	value;

	while (ac - 1 >= 1)
	{
		value = ft_atoi(av[ac - 1]);
		if (!ft_checker(av[ac - 1]) || is_dup(*stack, value))
			std_error();
		push_single_stack(stack, value);
		ac--;
	}
}
