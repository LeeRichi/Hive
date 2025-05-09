/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:47:55 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/09 11:59:30 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_thread_join(pthread_t monitor_thread, t_data *data,
	pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	if (pthread_join(monitor_thread, NULL) != 0)
	{
		destroy_all(data, forks);
		return (print_exit("pthread_join monitor failed"));
	}
	i = 0;
	while (i < data->philos->num_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			destroy_all(data, forks);
			return (print_exit("pthread_join philo failed"));
		}
		i++;
	}
	destroy_all(data, forks);
	return (1);
}

int	ft_thread_init(t_data *data, pthread_mutex_t *forks, t_philo *philos)
{
	int			i;
	pthread_t	monitor_thread;

	data->num_forks_initialized = 0;
	data->num_philos_initialized = 0;
	i = 0;
	while (i < data->philos[0].num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error: pthread_mutex_init failed for forks[%d]\n", i);
			destroy_all(data, forks);
			return (0);
		}
		i++;
		data->num_forks_initialized++;
	}
	pthread_mutex_lock(philos->write_lock);
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
	pthread_mutex_unlock(philos->write_lock);
	return (ft_thread_join(monitor_thread, data, forks, philos));
}

int	philo_init(t_philo *philos, char **av, t_data *data,
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
		if (philos[i].starting_time == (size_t)-1)
			return (0);	
		philos[i].time_of_last_meal = get_current_time();
		if (philos[i].time_of_last_meal == (size_t)-1)
			return (0);	
		philos[i].dead_flag_pointer = &data->dead_flag;
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
        if (pthread_mutex_init(&philos[i].eat_lock, NULL) != 0)
        {
            printf("Error: pthread_mutex_init failed for philosopher %d's eat_lock\n", philos[i].id);
            return 0;
        }
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % philos[i].num_philos];
		i++;
		data->num_philos_initialized++;
	}
	return (1);
}

int data_init(t_data *data, char **av, t_philo *philos, pthread_mutex_t *forks)
{
    data->philos = philos;
    data->dead_flag = 0;

    if (pthread_mutex_init(&data->write_lock, NULL) != 0)
    {
        printf("Error: pthread_mutex_init failed for write_lock\n");
        return (0);
    }
    if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
    {
        printf("Error: pthread_mutex_init failed for dead_lock\n");
        pthread_mutex_destroy(&data->write_lock);
        return (0);
    }
    if (!philo_init(philos, av, data, forks))
    {
        pthread_mutex_destroy(&data->write_lock);
        pthread_mutex_destroy(&data->dead_lock);
        return (0);
    }
    if (ft_thread_init(data, forks, philos) != 1)
    {
        pthread_mutex_destroy(&data->write_lock);
        pthread_mutex_destroy(&data->dead_lock);
        return (0);
    }
    return (1);
}


void	destroy_all(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->num_forks_initialized)
		pthread_mutex_destroy(&forks[i++]);
	i = 0;
	while (i < data->num_philos_initialized)
		pthread_mutex_destroy(&data->philos[i++].eat_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
}

