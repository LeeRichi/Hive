/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:55:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/14 10:59:59 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_usleep(long time, t_philo *philo)
{
	long	start;

	start = get_current_time();
	if (start == -1)
	{
		printf("Error: get_current_time failed in ft_usleep()\n");
		return (0);
	}
	while (get_current_time() - start < time)
	{
		pthread_mutex_lock(philo->dead_lock);
		if (*philo->dead_flag_pointer)
		{
			pthread_mutex_unlock(philo->dead_lock);
			return (0);
		}
		pthread_mutex_unlock(philo->dead_lock);
		usleep(100);
	}
	return (1);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error: gettimeofday() failed\n");
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(char *str, t_philo *philo, int id)
{
	long	current_time;

	pthread_mutex_lock(philo->write_lock);
	current_time = get_current_time();
	if (current_time == -1)
	{
		printf("Error: get_current_time failed in print_message()\n");
		return ;
	}
	if (*philo->dead_flag_pointer)
	{
		if (ft_strcmp(str, "died") == 0)
			printf("%zu %d %s\n", current_time - philo->starting_time,
				id, str);
	}
	else
		printf("%zu %d %s\n", current_time - philo->starting_time,
			id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	print_exit(char *str)
{
	printf("%s", str);
	return (0);
}
