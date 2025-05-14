/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:58:56 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/14 10:58:29 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	did_not_starve_help(t_philo *p, int i)
{
	pthread_mutex_unlock(p[i].dead_lock);
	pthread_mutex_unlock(&p[i].eat_lock);
}

int	did_not_starve(t_philo *p)
{
	int		i;
	long	current_time;

	i = 0;
	while (i < p[0].num_philos)
	{
		pthread_mutex_lock(&p[i].eat_lock);
		current_time = get_current_time();
		if (current_time == -1)
		{
			pthread_mutex_unlock(&p[i].eat_lock);
			return (0);
		}
		if (current_time - p[i].time_of_last_meal >= p[i].time_to_die)
		{
			pthread_mutex_lock(p[i].dead_lock);
			*p->dead_flag_pointer = 1;
			print_message("died", p, p[i].id);
			did_not_starve_help(p, i);
			return (0);
		}
		pthread_mutex_unlock(&p[i].eat_lock);
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
		pthread_mutex_lock(&philos[i].eat_lock);
		if (philos[i].num_times_eaten >= philos[i].num_times_to_eat)
			done++;
		pthread_mutex_unlock(&philos[i].eat_lock);
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
	pthread_mutex_lock(philos->write_lock);
	pthread_mutex_unlock(philos->write_lock);
	while (1)
	{
		if (!did_not_starve(philos) || everyone_eats_enough_time(philos))
			break ;
	}
	return (arg);
}
