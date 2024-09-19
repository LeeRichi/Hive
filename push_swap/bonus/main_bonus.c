/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:50:25 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/19 14:13:06 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static char	*ft_ins_check(t_list **a_stack, t_list **b_stack, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(a_stack, 0);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(b_stack, 0);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(a_stack, b_stack);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(a_stack, b_stack);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(a_stack, b_stack);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(a_stack, 0);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(b_stack, 0);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(a_stack, b_stack);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(a_stack, 0);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(b_stack, 0);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(a_stack, b_stack);
	else
		std_error();
	return (get_next_line(0));
}

static void	bonus_sort(t_list **a_stack, t_list **b_stack, char *instruction)
{
	char	*res;

	while (instruction && *instruction != '\n')
	{
		res = instruction;
		instruction = ft_ins_check(a_stack, b_stack, instruction);
		free(res);
	}
	if (is_sorted(*a_stack) && !(*b_stack))
		ft_printf("OK\n");
	else if (*b_stack || !is_sorted(*a_stack))
		ft_printf("KO\n");
	free(instruction);
}

void	bonus_checker(char *instruction, t_list **a_stack, t_list **b_stack)
{
	if (!instruction && is_sorted(*a_stack))
		ft_printf("OK");
	else if (!instruction && !is_sorted(*a_stack))
		ft_printf("KO");
	else
		bonus_sort(a_stack, b_stack, instruction);
}

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		am_words;
	char	**split_av;
	char	*instruction;

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
	instruction = get_next_line(0);
	bonus_checker(instruction, &a_stack, &b_stack);
	ft_free_throw(a_stack);
	ft_free_throw(b_stack);
	return (0);
}
