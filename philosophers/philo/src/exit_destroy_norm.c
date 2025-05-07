/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_destroy_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:17:30 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/07 16:21:48 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	exit_destroy_norm(char *str, t_data *data, pthread_mutex_t *forks)
{
	destroy_all(data, forks);
	return (print_exit(str));
}
