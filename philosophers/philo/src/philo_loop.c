/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:59:52 by chlee2            #+#    #+#             */
/*   Updated: 2025/04/14 10:23:02 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int ft_usleep(int time)
// {
//     int start;

//     start = get_current_time();
//     while (get_current_time() - start < time)
//         usleep(100);
//     return (0);
// }

size_t get_current_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
    {
        perror("gettimeofday");
        return (0);
    }

    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void print_message(char *str, t_philo *philo, int id)
{
    pthread_mutex_lock(philo->write_lock);
    printf("%zu %d %s\n", get_current_time() - philo->starting_time, id, str);
    pthread_mutex_unlock(philo->write_lock);
}

void think(t_philo *philo)
{
    print_message("is thinking", philo, philo->id);
    usleep(1000); //needs to change
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->l_fork);
    print_message("has taken a l_fork", philo, philo->id);

    pthread_mutex_lock(philo->r_fork);
    print_message("has taken a r_fork", philo, philo->id);

    print_message("is eating", philo, philo->id);
	philo->time_of_last_meal = get_current_time();

	usleep(philo->time_to_eat * 1000);
    philo->num_times_eaten++;
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void sleep(t_philo *philo)
{
    // Philosopher goes to sleep
    print_message("is sleeping", philo, philo->id);
    usleep(philo->time_to_sleep * 1000);  // Convert time_to_sleep from ms to microseconds
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead_flag == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	return (pthread_mutex_unlock(philo->dead_lock), 0);
}

void *philo_loop(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    // Access the philosopher's data directly
    while (!dead_loop(philo))
    {

		// Pick up forks (mutexes for left and right forks)
        // pthread_mutex_lock(philo->l_fork);
        // print_message("has taken a fork", philo, philo->id);
        // pthread_mutex_lock(philo->r_fork);
        // print_message("has taken a fork", philo, philo->id);

        // Eat
        eat(philo);

        // Put down forks
        pthread_mutex_unlock(philo->l_fork);
        pthread_mutex_unlock(philo->r_fork);

        // Sleep
        sleep(philo);
        // Think
        think(philo);
    }

    return NULL;
}

