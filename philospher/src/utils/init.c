/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:31 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/23 16:20:29 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void assign_forks(t_philosopher *philo, t_data *data)
{
	int left_idx = philo->id - 1;
	int right_idx = philo->id % data->num_philosophers;
	
	if (philo->id % 2 == 1)
	{
		philo->left_fork = &data->forks[right_idx];
		philo->right_fork = &data->forks[left_idx];
	}
	else
	{
		philo->left_fork = &data->forks[right_idx];
		philo->right_fork = &data->forks[left_idx];
	}
}

int init_philo(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].last_meal_time = 0;
		data->philosophers[i].left_fork = &data->forks[i];
		data->philosophers[i].right_fork = &data->forks[(i + 1) % data->num_philosophers];
		data->philosophers[i].data = data;
		if (pthread_mutex_init(&data->philosophers[i].meals_eaten_, NULL) != 0)
        {
            printf("%sMeals eaten mutex initialization failed for philosopher %d!\n", RED, i + 1);
            cleanup_partial_philosophers(data, i);
            return (1);
        }
        
        if (pthread_mutex_init(&data->philosophers[i].last_meal_t, NULL) != 0)
        {
            printf("%sLast meal mutex initialization failed for philosopher %d!\n", RED, i + 1);
            pthread_mutex_destroy(&data->philosophers[i].meals_eaten_);
            cleanup_partial_philosophers(data, i);
            return (1);
        }
	}
	return (0);
}

int init_data(t_data *data)
{
    int i;
    
    data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
    if (!data->philosophers || !data->forks)
        return (1);
    i = -1;
    while (++i < data->num_philosophers)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            printf("%sFork mutex initialization failed for fork %d!\n", RED, i);
            return (cleaup(data), 1);
        }
    }
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
    {
        printf("%sPrint mutex initialization failed!\n", RED);
        return (cleanup(data), 1);
    }
    if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
    {
        printf("%sDeath mutex initialization failed!\n", RED);
        return (cleanup(data), 1);
    }
    return (data->simulation_ended = 0, init_philo(data));
}
