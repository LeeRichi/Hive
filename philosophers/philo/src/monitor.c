/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:58:56 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/23 16:35:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	did_not_starve(t_philo *p)
{
	int	i;
	int	num;

	num = p[0].num_philos;
	i = 0;
	while (i < num)
	{
		pthread_mutex_lock(p[i].eat_lock);
		if (get_current_time() - p[i].time_of_last_meal >= p[i].time_to_die)
		{
			pthread_mutex_lock(p[i].dead_lock);
			*p->dead_flag_pointer = 1;
			print_message("died", p, p[i].id);
			pthread_mutex_unlock(p[i].dead_lock);
			pthread_mutex_unlock(p[i].eat_lock);
			return (0);
		}
		pthread_mutex_unlock(p[i].eat_lock);
		i++;
	}
	return (1);
}

int	everyone_eats_enough_time(t_philo *philos)
{
	int	i;
	int	done;
	int	num;

	num = philos[0].num_philos;
	done = 0;
	if ((int)philos[0].num_times_to_eat == -1)
		return (0);
	i = 0;
	while (i < num)
	{
		pthread_mutex_lock(philos[i].eat_lock);
		if (philos[i].num_times_eaten >= philos[i].num_times_to_eat)
			done++;
		pthread_mutex_unlock(philos[i].eat_lock);
		i++;
	}
	if (done == i)
	{
		pthread_mutex_lock(philos->dead_lock);
		*philos->dead_flag_pointer = 1;
		pthread_mutex_unlock(philos->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor_function(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (!did_not_starve(philos) || everyone_eats_enough_time(philos))
			break ;
	}
	return (arg);
}
