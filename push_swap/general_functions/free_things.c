/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LEECHI <LEECHI@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:29:06 by LEECHI            #+#    #+#             */
/*   Updated: 2024/08/05 12:34:09 by LEECHI           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_throw(t_list *stack)
{
	if(stack == NULL)
		return ;
	t_list	*temp;

	temp = stack;
	stack = stack->next;
	free(temp);
}

//designed for split_av
void	ft_two_free_throws(char **split_av)
{
	if(split_av == NULL)
		return ;
	int i;

	i = 0;
    while (split_av[i])
    {
        free(split_av[i]);
        i++;
    }
    free(split_av);
}

