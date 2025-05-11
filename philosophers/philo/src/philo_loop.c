/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:59:52 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/11 19:13:54 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	size_t	current_time;

	current_time = get_current_time();
	if (current_time == (size_t)-1)
	{
		printf("Error: get_current_time failed in think()\n");
		*philo->dead_flag_pointer = 1;
		return ;
	}
	if (current_time - philo->time_of_last_meal > philo->time_to_eat / 2)
		usleep(500);
	else
		usleep(1000);
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
	// pthread_mutex_lock(philo->write_lock);
	// pthread_mutex_unlock(philo->write_lock);
	if ((philo->id) % 2 == 0)
		ft_usleep(2, philo);
	else if (philo->num_philos >= 100 && philo->num_philos < 190)
		ft_usleep(6, philo);
	else if (philo->num_philos >= 190)
		ft_usleep(11, philo);
	while (!dead_loop(philo))
	{
		think(philo);
		if (dead_loop(philo))
			break ;
		eat(philo);
		if (dead_loop(philo))
			break ;
		dream(philo);
		if (dead_loop(philo))
			break ;
	}
	return (NULL);
}
