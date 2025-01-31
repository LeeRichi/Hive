/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:30:21 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/31 18:16:14 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define MAX_NUM_PHILO 200

typedef struct s_philo
{
	pthread_t thread;
	//av
	int num_philos;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	int num_times_to_eat;
	//process
	int num_times_eaten;
	int is_eating; //flag
	size_t starting_time;
	size_t time_of_last_meal;
	int *dead_flag;
	// pointers to central values
	pthread_mutex_t *write_lock;
	pthread_mutex_t *dead_lock;
	pthread_mutex_t *eat_lock;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork
} t_philo;

typedef struct s_data
{
	t_philo *philos;
	int dead_flag;
	//central locks
	pthread_mutex_t write_lock;
	pthread_mutex_t dead_lock;
	pthread_mutex_t eat_lock;

} t_data;

//helpers.h
int ft_atoi(const char *str);
void print_exit(char *str);
size_t get_time(void);
void destory_all(t_data *data, pthread_mutex_t *forks);

void monitor_function(t_data data);

void philo_loop(t_philo philo);

#endif
