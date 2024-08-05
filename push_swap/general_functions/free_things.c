/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:29:06 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/05 18:08:14 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_throw(t_list *stack)
{
	t_list	*temp;

	if (stack == NULL)
		return ;
	temp = stack;
	stack = stack->next;
	free(temp);
}

//designed for split_av
void	ft_two_free_throws(char **split_av)
{
	int	i;

	if (split_av == NULL)
		return ;
	i = 0;
	while (split_av[i])
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
}
