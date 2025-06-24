/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:31 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/24 15:48:01 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

void	init_forks(t_philosopher *philo, t_data *data)
{
	int	left_idx;
	int	right_idx;

	left_idx = philo->id - 1;
	right_idx = philo->id % data->num_philosophers;
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

//data->philosophers[i].left_fork = &data->forks[i];
//data->philosophers[i].right_fork = 
//&data->forks[(i + 1) % data->num_philosophers];

int	init_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].meals_eaten = 0;
		data->philosophers[i].last_meal_time = 0;
		init_forks(&data->philosophers[i], data);
		data->philosophers[i].data = data;
		if (pthread_mutex_init(&data->philosophers[i].meals_eaten_, NULL) != 0)
		{
			printf("%sMeals eaten mutex initialization failed!\n", RED);
			return (cleanup_partial_philosophers(data, i), 1);
		}
		if (pthread_mutex_init(&data->philosophers[i].last_meal_t, NULL) != 0)
		{
			printf("%smeal mutex initialization failed!\n", RED);
			pthread_mutex_destroy(&data->philosophers[i].meals_eaten_);
			return (cleanup_partial_philosophers(data, i), 1);
		}
	}
	return (0);
}

int	init_data(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (!data->philosophers || !data->forks)
		return (1);
	i = -1;
	while (++i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (cleanup(data), printf("%sinitialization failed!\n", RED), 1);
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
