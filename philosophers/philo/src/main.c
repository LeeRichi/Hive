/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:30:24 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/08 14:05:29 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int ft_is_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int arg_check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		print_exit("Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]");
	if (atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_NUM_PHILO || !ft_is_num(av[1]))
	{
		print_exit("Invalid number of philos.");
		printf("Invalid number of philos.");
		exit(EXIT_FAILURE);
	}
	if (atoi(av[2]) <= 0 || !ft_is_num(av[2]))
		print_exit("Invalid time_to_die.");
	if (atoi(av[3]) <= 0 || !ft_is_num(av[3]))
		print_exit("Invalid time_to_eat.");
	if (atoi(av[4]) <= 0 || !ft_is_num(av[4]))
		print_exit("Invalid time_to_sleep.");
	if (av[5] != NULL && (atoi(av[5]) <= 0 || !ft_is_num(av[5])))
		print_exit("Invalid times each philosopher must eat.");
	return (1);
}

// ◦ time_to_die (in milliseconds):
// If a philosopher didn’t start eating time_to_die milliseconds since the beginning of
// their last meal or the beginning of the simulation, they die.
// ◦ time_to_eat (in milliseconds):
// The time it takes for a philosopher to eat.
// During that time, they will need to hold two forks.
// ◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping
int main(int ac, char **av)
{
	t_data data;
	t_philo philos[MAX_NUM_PHILO];
	pthread_mutex_t forks[MAX_NUM_PHILO];

	if (!arg_check(ac, av))
		return (EXIT_FAILURE);
	data_init(&data, av, philos, forks);
	free(data.philos);
	return (EXIT_SUCCESS);
}
