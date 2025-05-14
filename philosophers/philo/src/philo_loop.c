/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:59:52 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/14 13:58:51 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	if (philo->is_eating)
		return ;
	print_message("is thinking", philo, philo->id);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message("has taken a fork", philo, philo->id);
	if (philo->num_philos == 1)
	{
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->eat_lock);
	print_message("has taken a fork", philo, philo->id);
	philo->is_eating = 1;
	print_message("is eating", philo, philo->id);
	philo->time_of_last_meal = get_current_time();
	eat_help(philo);
	philo->num_times_eaten++;
	pthread_mutex_unlock(&philo->eat_lock);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(&philo->eat_lock);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->eat_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	dream(t_philo *philo)
{
	print_message("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep, philo);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag_pointer == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_current_time() < philo->starting_time)
		usleep(200);
	manual_dealy(philo);
	if (philo->id % 2 != 0 && philo->num_philos != 1)
	{
		think(philo);
		ft_usleep(philo->num_philos / 2, philo);
	}
	while (!dead_loop(philo))
	{
		if (dead_loop(philo))
			break ;
		eat(philo);
		if (dead_loop(philo))
			break ;
		dream(philo);
		if (dead_loop(philo))
			break ;
		think(philo);
	}
	return (NULL);
}
