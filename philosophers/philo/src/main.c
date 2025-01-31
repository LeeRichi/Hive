/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:30:24 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/31 18:16:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void data_init(t_data *data, char **av, t_philo *philos, pthread_mutex_t *forks)
{
	int i;

	data->philos = philos;
	data->dead_flag = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].num_philos = ft_atoi(av[1]);
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		philos[i].num_times_to_eat = -1;
		if (av[6])
			philos[i].num_times_to_eat = atoi(av[5]);
		philos[i].num_times_eaten = 0;
		philos[i].is_eating = 0;
		philos[i].starting_time = 0;
		philos[i].time_of_last_meal = 0;
		philos[i].dead_flag = 0;
		i++;
	}

	//forks
	i = 0;
	while(i < data->philos[0].num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}

	pthread_t monitor_thread;

	//thread the last
	if (pthread_create(monitor_thread, NULL, monitor_function, &data) != 0)
	{
		print_exit("pthread_create monitor failed");
		destory_all(data, forks);
	}
	i = 0;
	while(i < data->philos->num_philos)
	{
		if (pthread_create(philos[i].thread, NULL, philo_loop, &philos[i]) != 0)
		{
			print_exit("pthread_create monitor failed");
			destory_all(data, forks);
		}
	}
	//destory all
}

int arg_check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		print_exit("Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]");

	if (atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_NUM_PHILO || !is_num(av[1]))
	{
		print_exit("Invalid number of philos.");
		printf("Invalid number of philos.");
		exit(EXIT_FAILURE);
	}
	if (atoi(av[2]) <= 0 || !is_num(av[2]))
		print_exit("Invalid time_to_die.");
	if (atoi(av[3]) <= 0 || !is_num(av[3]))
		print_exit("Invalid time_to_eat.");
	if (atoi(av[4]) <= 0 || !is_num(av[4]))
		print_exit("Invalid time_to_sleep.");
	if (atoi(av[5]) <= 0 || !is_num(av[5]))
		print_exit("Invalid times each philosopher must eat.");
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
