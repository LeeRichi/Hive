/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:55:06 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/22 15:24:42 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < time)
		usleep(100);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		perror("gettimeofday");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(char *str, t_philo *philo, int id)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d %s\n", get_current_time() - philo->starting_time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' && str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void	print_exit(char *str)
{
	printf("%s", str);
	exit(EXIT_FAILURE);
}
