/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:59:52 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/22 14:55:12 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int ft_usleep(size_t time)
// {
//     size_t start;

//     start = get_current_time();
//     while (get_current_time() - start < time)
//         usleep(100);
//     return (0);
// }

// size_t get_current_time(void)
// {
//     struct timeval time;

//     if (gettimeofday(&time, NULL) == -1)
//     {
//         perror("gettimeofday");
//         return (0);
//     }

//     return (time.tv_sec * 1000 + time.tv_usec / 1000);
// }

// void print_message(char *str, t_philo *philo, int id)
// {
//     pthread_mutex_lock(philo->write_lock);
//     printf("%zu %d %s\n", get_current_time() - philo->starting_time, id, str);
//     pthread_mutex_unlock(philo->write_lock);
// }

void think(t_philo *philo)
{
    if (get_current_time() - philo->time_of_last_meal > philo->time_to_eat / 2)
        usleep(500);
    else
        usleep(1000);
    print_message("is thinking", philo, philo->id);
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    print_message("has taken a l_fork", philo, philo->id);
    if (philo->num_philos == 1)
    {
        ft_usleep(philo->time_to_die);
        pthread_mutex_unlock(philo->l_fork);
        return ;
    }
    pthread_mutex_lock(philo->r_fork);
    print_message("has taken a r_fork", philo, philo->id);
    philo->is_eating = 1;
    print_message("is eating", philo, philo->id);
    pthread_mutex_lock(philo->eat_lock);
    philo->time_of_last_meal = get_current_time();
    philo->num_times_eaten++;
    pthread_mutex_unlock(philo->eat_lock);
    ft_usleep(philo->time_to_eat);
    philo->is_eating = 0;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void dream(t_philo *philo)
{
    print_message("is sleeping", philo, philo->id);
    usleep(philo->time_to_sleep * 1000);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead_flag_pointer == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void *philo_loop(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if ((philo->id) % 2 == 0)
        ft_usleep(1);
    
    while (!dead_loop(philo))
    {
        if (dead_loop(philo))
            break;
        eat(philo);
        if (dead_loop(philo))
            break;
        dream(philo);
        if (dead_loop(philo))
            break;
        think(philo);
    }
    return NULL;
}

