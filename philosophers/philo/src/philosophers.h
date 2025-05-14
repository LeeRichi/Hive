/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:30:21 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/14 14:04:24 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
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
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_times_to_eat;
	long			num_times_eaten;
	int				is_eating;
	long			starting_time;
	long			time_of_last_meal;
	int				dead_flag;
	int				*dead_flag_pointer;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	int				num_forks_initialized;
	int				num_philos_initialized;
}	t_data;

int		ft_atoi(const char *str);
int		print_exit(char *str);
int		data_init(t_data *data, char **av, t_philo *philos,
			pthread_mutex_t *forks);
int		destroy_all(t_data *data, pthread_mutex_t *forks);
void	*monitor_function(void *args);
void	*philo_loop(void *arg);
long	get_current_time(void);
int		ft_usleep(long time, t_philo *philos);
void	print_message(char *str, t_philo *philo, int id);
int		is_num(char *str);
int		exit_destroy_norm(char *str, t_data *data, pthread_mutex_t *forks);
int		ft_strcmp(const char *s1, const char *s2);
void	eat_help(t_philo *philo);
void	philo_init_help(t_philo *philos, char **av, int i);
void	philo_init_help_2(t_philo *philos, t_data *data, int i);
int		ft_forks_init_fail(t_data *data, pthread_mutex_t *forks, int i);
void	manual_dealy(t_philo *philo);
void	inject_time_each(t_data *data, t_philo *philos);

#endif
