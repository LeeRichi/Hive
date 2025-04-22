/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:17:30 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/22 15:20:46 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	exit_destroy_norm(char *str, t_data *data, pthread_mutex_t *forks)
{
	destroy_all(data, forks);
	print_exit(str);
}
