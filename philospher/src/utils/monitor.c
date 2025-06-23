/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:14:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/23 14:44:41 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void *death_monitor(void *arg)
{
    int i;
    t_data *data = (t_data *)arg;
    
    while (!simulation_ended(data))
    {
        i = -1;
        while (++i < data->num_philosophers)
        {
            if (is_philosopher_dead(&data->philosophers[i]))
            {
                pthread_mutex_lock(&data->death_mutex);
                if (data->simulation_ended == 0)
                {
                    data->simulation_ended = 1;
                    print_death_message(&data->philosophers[i]);
                }
                return (pthread_mutex_unlock(&data->death_mutex), NULL);
            }
        }
        if (all_philosophers_satisfied(data) == 1)
        {
            pthread_mutex_lock(&data->death_mutex);
            if (!data->simulation_ended)
                data->simulation_ended = 1;
            return (pthread_mutex_unlock(&data->death_mutex), NULL);
        }
        usleep(500);
    }
    return (NULL);
}

int all_philosophers_satisfied(t_data *data)
{
    int i;
    
    if (data->must_eat_count == -13)
        return (0);
    i = -1;
    while (++i < data->num_philosophers)
    {
        pthread_mutex_lock(&data->philosophers[i].meals_eaten_);
        int meals = data->philosophers[i].meals_eaten;
        pthread_mutex_unlock(&data->philosophers[i].meals_eaten_);
        
        if (meals < data->must_eat_count)
            return (0);
    }
    return (1);
}

int is_philosopher_dead(t_philosopher *philo)
{
    long current_time;
    
    current_time = get_current_time();
    pthread_mutex_lock(&philo->last_meal_t);
    long last_meal_time = philo->last_meal_time;
    pthread_mutex_unlock(&philo->last_meal_t);
    long time_since_meal = current_time - last_meal_time;
    return (time_since_meal > philo->data->time_to_die);
}

void print_death_message(t_philosopher *philo)
{
    long timestamp = get_current_time() - philo->data->start_time;
    printf("%s%ld ms %sPhilosopher %d %shas died%s\n",
        CYAN, timestamp, BOLD, philo->id, RED, RESET);
}

int check_meal_completion(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_);
	if (philo->meals_eaten >= philo->data->must_eat_count)
	{
		pthread_mutex_unlock(&philo->meals_eaten_);
		return (1);
	}
	pthread_mutex_unlock(&philo->meals_eaten_);
	return (0);
}
