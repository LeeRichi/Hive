/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:40:29 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/31 18:22:05 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1 means dup
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

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		am_words;
	char	**split_av;

	a_stack = NULL;
	b_stack = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		split_av = ps_split(av[1], &am_words);
		initialize_stack(&a_stack, am_words + 1, split_av);
		ft_two_free_throws(split_av);
	}
	else
		initialize_stack(&a_stack, ac, av);
	initialize_stack(&b_stack, 0, NULL);
	sort_stack(&a_stack, &b_stack);
	ft_free_throw(a_stack);
	ft_free_throw(b_stack);
	return (0);
}
