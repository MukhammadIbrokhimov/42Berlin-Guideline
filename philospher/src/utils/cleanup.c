/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:16:13 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/23 12:46:48 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void    cleanup(t_data *data)
{
    int i;
    
    if (data->philosophers)
    {
        i = -1;
        while (++i < data->num_philosophers)
        {
            if (pthread_mutex_destroy(&data->philosophers[i].meals_eaten_) != 0)
                printf("Warning: Failed to destroy meals_eaten mutex for philosopher %d\n", i);            
            if (pthread_mutex_destroy(&data->philosophers[i].last_meal_t) != 0)
                printf("Warning: Failed to destroy last_meal_t mutex for philosopher %d\n", i);
        }
        free(data->philosophers);
        data->philosophers = NULL;
    }
    if (data->forks)
    {
        for (i = 0; i < data->num_philosophers; i++)
        {
            if (pthread_mutex_destroy(&data->forks[i]) != 0)
                printf("Warning: Failed to destroy fork mutex %d\n", i);
        }
        free(data->forks);
        data->forks = NULL;
    }
    if (pthread_mutex_destroy(&data->print_mutex) != 0)
        printf("Warning: Failed to destroy print mutex\n");
    if (pthread_mutex_destroy(&data->death_mutex) != 0)
        printf("Warning: Failed to destroy death mutex\n");
}

void cleanup_forks(t_data *data, int count)
{
    int i;
    for (i = 0; i < count; i++)
        pthread_mutex_destroy(&data->forks[i]);
    free(data->philosophers);
    free(data->forks);
}

void cleanup_partial_philosophers(t_data *data, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        pthread_mutex_destroy(&data->philosophers[i].meals_eaten_);
        pthread_mutex_destroy(&data->philosophers[i].last_meal_t);
    }
}
