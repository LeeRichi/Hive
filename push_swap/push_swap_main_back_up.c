
// # include <stdio.h>
// # include <stdlib.h>

// #include "push_swap.h"

// int is_dup(t_list *stack, int value) //1 is dup
// {
// 	while(stack)
// 	{
// 		if(stack->nbr == value)
// 			return (1);
// 		stack = stack->next;
// 	}
// 	return (0);
// }

// int ft_checker(char *str) //1 is pass
// {
// 	if(str[0] == '-' && str[1] == '1')
// 		return (1);
// 	// if(str[0] == '-')
// 	// 	return (1);
// 	else if(str[0] == '0')
// 		return (1);
// 	else if(ft_atoi(str) != 0 && ft_atoi(str) != -1)//if it's 0 or -1, that means overflow.
// 		return (1);
// 	else
// 		return (0);
// }

// void initialize_stack(t_list **stack, int ac, char **av)
// {
// 	// while(ac - 1 >= 0)
// 	while(ac - 1 >= 1)
// 	{
// 		int value = ft_atoi(av[ac - 1]);

// 		if (!ft_checker(av[ac - 1]) || is_dup(*stack, value))
//         {
//             ft_printf("Error\n");
//             exit(1);
//         }
// 		push_single_stack(stack, value);
// 		ac--;
// 	}
// }

// void print_stack(t_list *stack)
// {
// 	while(stack)
// 	{
// 		ft_printf("%d\n", stack->nbr);
// 		stack = stack->next;
// 	}
// }

// int main(int ac, char **av)
// {
// 	t_list *a_stack = NULL;
// 	t_list *b_stack = NULL;
// 	int am_words;

// 	char **split_av;
// 	if(ac <= 1)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	else if(ac == 2)
// 	{
// 		split_av = ps_split(av[1], &am_words);
// 		initialize_stack(&a_stack, am_words + 1, split_av);
// 	}
// 	else
// 		initialize_stack(&a_stack, ac, av);
// 	initialize_stack(&b_stack, 0, NULL);

// 	// printf("begining: \n");
// 	// print_stack(a_stack);

// 	//printf("sorting now...: \n");
// 	sort_stack(&a_stack, &b_stack);

// 	// printf("After: \n");
// 	// print_stack(a_stack);

// 	// printf("B-----: \n");
// 	// print_stack(b_stack);

// 	while (a_stack)
//     {
//         t_list *temp = a_stack;
//         a_stack = a_stack->next;
//         free(temp);
//     }

//     return 0;
// }
