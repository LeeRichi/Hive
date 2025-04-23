/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:30:21 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/23 14:39:02 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define MAX_NUM_PHILO 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				num_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			num_times_to_eat;
	size_t			num_times_eaten;
	int				is_eating;
	size_t			starting_time;
	size_t			time_of_last_meal;
	int				dead_flag;
	int				*dead_flag_pointer;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*eat_lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat_lock;
}	t_data;

int		ft_atoi(const char *str);
void	print_exit(char *str);
void	data_init(t_data *data, char **av, t_philo *philos,
			pthread_mutex_t *forks);
void	destroy_all(t_data *data, pthread_mutex_t *forks);
void	*monitor_function(void *args);
void	*philo_loop(void *arg);
size_t	get_current_time(void);
int		ft_usleep(size_t time);
void	print_message(char *str, t_philo *philo, int id);
int		is_num(char *str);
void	exit_destroy_norm(char *str, t_data *data, pthread_mutex_t *forks);

int		ft_strcmp(const char *s1, const char *s2);


#endif
