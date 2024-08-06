// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_utils.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/05 17:42:13 by chlee2            #+#    #+#             */
// /*   Updated: 2024/08/05 17:42:13 by chlee2           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static void swap_list(t_list *a, t_list *b)
// {
// 	int temp;

// 	if(a && b)
// 	{
// 		temp = a->nbr;
// 		a->nbr = b->nbr;
// 		b->nbr = temp;
// 	}
// }

// void push(t_list **x, t_list **y)
// {
// 	t_list *temp;

// 	if(x && *x)
// 	{
// 		temp = *x;
// 		*x = (*x)->next;
// 		temp->next = *y;
// 		*y = temp;
// 	}
// }

// void rotate(t_list **lst)
// {
// 	t_list *temp;
// 	t_list *current;

// 	if(*lst && (*lst)->next)
// 	{
// 		temp = *lst;
// 		*lst = (*lst)->next;
// 		temp->next = NULL;

// 		current = *lst;
// 		while(current->next)
// 			current = current->next;
// 		current->next = temp;
// 	}
// }

// void reverse_rotate(t_list **lst)
// {
// 	t_list *temp;
// 	t_list *current;

// 	if(*lst && (*lst)->next)
// 	{
// 		current = *lst;
// 		while(current->next->next) //to the second next
// 			current = current->next;

// 		temp = current->next;
// 		current->next = NULL;

// 		temp->next = *lst;
// 		*lst = temp;
// 	}
// }

// void sa(t_list **stack_a, int print)
// {
// 	if(stack_a && *stack_a && (*stack_a)->next)
// 		swap_list(*stack_a, (*stack_a)->next);
// 	if(print)
// 		ft_printf("sa\n");
// }

// void sb(t_list **stack_b, int print)
// {
// 	if(stack_b && *stack_b && (*stack_b)->next)
// 		swap_list(*stack_b, (*stack_b)->next);
// 	if(print)
// 		ft_printf("sb\n");
// }

// void ss(t_list **stack_a, t_list **stack_b)
// {
// 	sa(stack_a, 0);
// 	sb(stack_b, 0);
// 	ft_printf("ss\n");
// }

// void pa(t_list **stack_a, t_list **stack_b)
// {
// 	if(stack_b && *stack_b)
// 	{
// 		push(stack_b, stack_a);
// 	}
// 	ft_printf("pa\n");
// }

// void pb(t_list **stack_a, t_list **stack_b)
// {
// 	if(stack_a && *stack_a)
// 	{
// 		push(stack_a, stack_b);
// 	}
// 	ft_printf("pb\n");
// }

// void ra(t_list **stack_a, int print)
// {
// 	rotate(stack_a);
// 	if(print)
// 		ft_printf("ra\n");
// }

// void rb(t_list **stack_b, int print)
// {
// 	rotate(stack_b);
// 	if(print)
// 		ft_printf("rb\n");
// }

// void rr(t_list **stack_a, t_list **stack_b)
// {
// 	ra(stack_a, 0);
// 	rb(stack_b, 0);
// 	ft_printf("rr\n");
// }

// void rra(t_list **stack_a, int print)
// {
// 	reverse_rotate(stack_a);
// 	if(print)
// 		ft_printf("rra\n");
// }

// void rrb(t_list **stack_b, int print)
// {
// 	reverse_rotate(stack_b);
// 	if(print)
// 		ft_printf("rrb\n");
// }

// void rrr(t_list **stack_a, t_list **stack_b)
// {
// 	rra(stack_a, 0);
// 	rrb(stack_b, 0);
// 	ft_printf("rrr\n");
// }
