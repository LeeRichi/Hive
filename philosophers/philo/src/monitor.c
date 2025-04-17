/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:58:56 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/17 19:43:56 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_alive(t_philo *philos)
{
    int i;
	
	i = 0;
	while (i < philos[i].num_philos)
	{
		pthread_mutex_lock(philos[i].eat_lock);
		if (get_current_time() - philos[i].time_of_last_meal >= philos[i].time_to_die)
		{
			pthread_mutex_lock(philos[i].dead_lock);
			printf("Philosopher %d has died\n", i);
			philos->dead_flag = 1;
			philos[i].dead_flag = 1; //single philo
			pthread_mutex_unlock(philos[i].dead_lock);
			pthread_mutex_unlock(philos[i].eat_lock);
			return (0);
		}
		pthread_mutex_unlock(philos[i].eat_lock);
		i++;
	}
	return (1);
}

int	is_all_eaten(t_philo *philos)
{
	int	i;
	int	done;

	done = 0;
	if ((int)philos[0].num_times_to_eat == -1)
		return (0);
	i = 0;
	while (i < philos[i].num_philos)
	{
		pthread_mutex_lock(philos[i].eat_lock);
		if (philos[i].num_times_eaten >= philos[i].num_times_to_eat)
			done++;
		pthread_mutex_unlock(philos[i].eat_lock);
		i++;
	}
	if (done == philos[0].num_philos)
	{
		printf("done is now %d\n", done);
		// pthread_mutex_lock(philos[0].dead_lock);
		pthread_mutex_lock(philos->dead_lock);

		
		philos->dead_flag = 1;

		//new
		*philos->dead_flag_pointer = 1;
		// philos[0].dead_flag = 1;
		// pthread_mutex_unlock(philos[0].dead_lock);
		pthread_mutex_unlock(philos->dead_lock);
		return (1);
	}
	return (0);
}

void *monitor_function(void *arg)
{
    t_philo *philos;

    philos = (t_philo *)arg;
    while (1)
    {
		
		if (!is_alive(philos) || is_all_eaten(philos))
		{
			printf("someone died!!!\n");
			break ;
		}
		
		// if (!is_alive(philos))

		// if (is_all_eaten(philos))
		// {
		// 	printf("everyone has eaten!!! Program ends..\n");
		// 	break ;
		// }
    }
    return (arg);
}
