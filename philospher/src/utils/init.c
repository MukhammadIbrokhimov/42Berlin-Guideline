/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:31 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/17 19:40:23 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	validate_data(t_data *data)
{
	if (data->num_philosophers < 2 || data->num_philosophers > 200)
		return (printf("%sNumber of philosophers must be greater than 1!\n", RED), 1);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (printf("%sTime values must be positive!\n", RED), 1);
	if (data->must_eat_count < 0 && data->must_eat_count != -13)
		return (printf("%sMust eat count cannot be negative!\n", RED), 1);
	return (0);
}

int	parse_data(int argc, char **argv, t_data *data)
{
	int	valid;

	valid = 1;
	if (argc < 5 || argc > 6)
		return (printf("%sIncorrect number of arguments!\n", RED), 1);
	data->num_philosophers = (int) ft_atol(argv[1], &valid);
	data->time_to_die = (long) ft_atol(argv[2], &valid);
	data->time_to_eat = (long) ft_atol(argv[3], &valid);
	data->time_to_sleep = (long) ft_atol(argv[4], &valid);
	data->must_eat_count = -13;
	if (argc == 6)
		data->must_eat_count = (int) ft_atol(argv[5], &valid);
	if (valid != 1)
		return (printf("%sNegative value is forbidden!\n", RED), 1);
	return (validate_data(data));
}

void assign_forks(t_philosopher *philo, t_data *data)
{
	int left_idx = philo->id - 1;
	int right_idx = philo->id % data->num_philosophers;
	
	// Critical: Assign forks in different order for odd/even philosophers
	if (philo->id % 2 == 1)
	{  // Odd philosophers: left first
		philo->left_fork = &data->forks[right_idx];
		philo->right_fork = &data->forks[left_idx];
	}
	else
	{  // Even philosophers: right first
		philo->left_fork = &data->forks[right_idx];
		philo->right_fork = &data->forks[left_idx];
	}
}

int	init_philo(t_data *data)
{
	int	i;

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
		//assign_forks(&data->philosophers[i], data);
	}
	return (0);
}

// Helper function for cleanup during failed initialization
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

int init_data(t_data *data)
{
    int i;
    
    // Allocate memory
    data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
    
    // FIX: Correct the malloc check - you were checking num_philosophers instead of philosophers!
    if (!data->philosophers || !data->forks)
    {
        printf("%sMemory allocation failed!\n", RED);
        // Clean up any successful allocations
        if (data->philosophers)
            free(data->philosophers);
        if (data->forks)
            free(data->forks);
        return (1);
    }
    
    // Initialize fork mutexes
    i = -1;
    while (++i < data->num_philosophers)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            printf("%sFork mutex initialization failed for fork %d!\n", RED, i);
            // Clean up previously initialized mutexes
            int j = 0;
            while (j < i)
            {
                pthread_mutex_destroy(&data->forks[j]);
                j++;
            }
            free(data->philosophers);
            free(data->forks);
            return (1);
        }
    }
    
    // Initialize shared mutexes
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
    {
        printf("%sPrint mutex initialization failed!\n", RED);
        cleanup_forks(data, data->num_philosophers);
        return (1);
    }
    
    if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
    {
        printf("%sDeath mutex initialization failed!\n", RED);
        pthread_mutex_destroy(&data->print_mutex);
        cleanup_forks(data, data->num_philosophers);
        return (1);
    }
    
    data->simulation_ended = 0;
    return (init_philo(data));
}