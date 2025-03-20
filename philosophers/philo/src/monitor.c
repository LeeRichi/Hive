/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:58:56 by chlee2            #+#    #+#             */
/*   Updated: 2025/03/20 11:59:59 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *monitor_function(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;

    while (!data->dead_flag)
    {
        i = 0;
        while (i < data->philos[0].num_philos)
        {
			printf("time: %zu\n", get_time());
			printf("time of last meal: %zu\n", data->philos[i].time_of_last_meal);
			printf("data->philos[i].time_to_die: %zu\n", data->philos[i].time_to_die);

            if (get_time() - data->philos[i].time_of_last_meal >= data->philos[i].time_to_die * 1000 * 1000)
            {
                data->philos[i].dead_flag = 1;
                data->dead_flag = 1;
                printf("Philosopher %d has died\n", i + 1);
                break;
            }
            i++;
        }
    }
    return NULL;
}
