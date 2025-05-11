/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:41:51 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/09 16:28:39 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_help(t_philo *philo)
{
	if (philo->time_of_last_meal == (size_t)-1)
	{
		printf("Error: get_current_time failed in eat()\n");
		*philo->dead_flag_pointer = 1;
		pthread_mutex_unlock(&philo->eat_lock);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
}

void	philo_init_help(t_philo *philos, char **av, int i)
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
}

void	philo_init_help_2(t_philo *philos, t_data *data, int i)
{
	philos[i].dead_flag_pointer = &data->dead_flag;
	philos[i].write_lock = &data->write_lock;
	philos[i].dead_lock = &data->dead_lock;
}

int	ft_forks_init_fail(t_data *data, pthread_mutex_t *forks, int i)
{
	printf("Error: pthread_mutex_init failed for forks[%d]\n", i);
	destroy_all(data, forks);
	return (0);
}
