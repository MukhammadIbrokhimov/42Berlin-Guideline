/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:16:13 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/17 19:41:11 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void cleanup(t_data *data)
{
    int i;
    
    if (data->philosophers)
    {
        i = -1;
        while (++i < data->num_philosophers)
        {
            // Only destroy mutexes that are unique to each philosopher
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