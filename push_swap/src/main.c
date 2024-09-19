/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:40:29 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/19 14:56:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		initialize_stack_by_string(&a_stack, am_words, split_av);
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
