/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:30:24 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/09 12:26:22 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (print_exit("Usage: ./philo n n n n (n)"));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_NUM_PHILO || !ft_num(av[1]))
	{
		return (print_exit("Invalid number of philos."));
		printf("Invalid number of philos.");
		return (0);
	}
	if (ft_atoi(av[2]) <= 0 || !ft_num(av[2]))
		return (print_exit("Invalid time_to_die."));
	if (ft_atoi(av[3]) <= 0 || !ft_num(av[3]))
		return (print_exit("Invalid time_to_eat."));
	if (ft_atoi(av[4]) <= 0 || !ft_num(av[4]))
		return (print_exit("Invalid time_to_sleep."));
	if (av[5] != NULL && (ft_atoi(av[5]) <= 0 || !ft_num(av[5])))
		return (print_exit("Invalid times each philosopher must eat."));
	return (1);
}

// ◦ time_to_die (in milliseconds):
// If a philosopher didn’t start eating
// time_to_die milliseconds since the beginning of
// their last meal or the beginning of the simulation, they die.
// ◦ time_to_eat (in milliseconds):
// The time it takes for a philosopher to eat.
// During that time, they will need to hold two forks.
// ◦ time_to_sleep (in milliseconds):
// The time a philosopher will spend sleeping
int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[MAX_NUM_PHILO];
	pthread_mutex_t	forks[MAX_NUM_PHILO];

	if (!arg_check(ac, av))
		return (EXIT_FAILURE);
	if (!data_init(&data, av, philos, forks))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
