/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:47:55 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/23 16:17:05 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thread_join(pthread_t monitor_thread, t_data *data,
	pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	if (pthread_join(monitor_thread, NULL) != 0)
	{
		print_exit("pthread_join monitor failed");
		destroy_all(data, forks);
	}
	i = 0;
	while (i < data->philos->num_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			print_exit("pthread_join philo failed");
			destroy_all(data, forks);
		}
		i++;
	}
	destroy_all(data, forks);
}

void	ft_thread_init(t_data *data, pthread_mutex_t *forks, t_philo *philos) //fix
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < data->philos[0].num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor_function,
			data->philos) != 0)
		exit_destroy_norm("pthread_create monitor failed", data, forks);
	i = 0;
	while (i < data->philos->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_loop, &data->philos[i]) != 0)
			exit_destroy_norm("pthread_create philo failed", data, forks);
		i++;
	}
	ft_thread_join(monitor_thread, data, forks, philos);
}

void	philo_init(t_philo *philos, char **av, t_data *data,
	pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].num_philos = ft_atoi(av[1]);
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		philos[i].num_times_to_eat = -1;
		if (av[5])
			philos[i].num_times_to_eat = ft_atoi(av[5]);
		philos[i].num_times_eaten = 0;
		philos[i].is_eating = 0;
		philos[i].starting_time = get_current_time();
		philos[i].time_of_last_meal = get_current_time();
		philos[i].dead_flag_pointer = &data->dead_flag;
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].eat_lock = &data->eat_lock;
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % philos[i].num_philos];
		i++;
	}
}

void	data_init(t_data *data, char **av, t_philo *philos,
	pthread_mutex_t *forks)
{
	data->philos = philos;
	data->dead_flag = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	philo_init(philos, av, data, forks);
	ft_thread_init(data, forks, philos);
}

void	destroy_all(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philos[0].num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->eat_lock);
}
