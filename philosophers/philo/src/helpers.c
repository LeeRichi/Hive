/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:47:55 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/31 18:18:00 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' && str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			flag;
	long		result;
	long		long_buffer;

	flag = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		long_buffer = result;
		result = 10 * result + (*str - 48);
		if (flag > 0 && result / 10 != long_buffer)
			return (-1);
		else if (flag < 0 && result / 10 != long_buffer)
			return (0);
		str++;
	}
	return (result * flag);
}

void print_exit(char *str)
{
	printf("%s", str);
	exit(EXIT_FAILURE);
}

size_t get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
	{
		print_exit("Fails on gettimeofday.\n");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

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

    // Initialize forks mutexes
    i = 0;
    while (i < data->philos[0].num_philos)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }

    pthread_t monitor_thread;

    // Create monitor thread
    if (pthread_create(&monitor_thread, NULL, monitor_function, &data) != 0)
    {
        print_exit("pthread_create monitor failed");
        destroy_all(data, forks);  // Destroy resources and exit
    }

    i = 0;
    while (i < data->philos->num_philos)
    {
        if (pthread_create(&philos[i].thread, NULL, philo_loop, &philos[i]) != 0)
        {
            print_exit("pthread_create philo failed");
            destroy_all(data, forks);  // Destroy resources and exit
        }
        i++;
    }

    // Join all threads (important for synchronization)
    if (pthread_join(monitor_thread, NULL) != 0)
    {
        print_exit("pthread_join monitor failed");
        destroy_all(data, forks);  // Destroy resources and exit
    }

    i = 0;
    while (i < data->philos->num_philos)
    {
        if (pthread_join(philos[i].thread, NULL) != 0)
        {
            print_exit("pthread_join philo failed");
            destroy_all(data, forks);  // Destroy resources and exit
        }
        i++;
    }

    // Now we can destroy all mutexes and free any resources
    destroy_all(data, forks);  // Properly clean up mutexes and other resources
}

void destroy_all(t_data *data, pthread_mutex_t *forks)
{
    int i;

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
