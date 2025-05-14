/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:17:30 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/14 14:05:05 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exit_destroy_norm(char *str, t_data *data, pthread_mutex_t *forks)
{
	destroy_all(data, forks);
	return (print_exit(str));
}

void	inject_time_each(t_data *data, t_philo *philos)
{
	long	time;
	int		i;

	time = get_current_time();
	i = 0;
	while (i < data->philos->num_philos)
	{
		philos[i].starting_time = time;
		i++;
	}
}
