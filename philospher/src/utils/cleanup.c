/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:16:13 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/24 12:57:34 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	cleanup(t_data *data)
{
	int	i;

	if (data->philosophers)
	{
		i = -1;
		cleanup_partial_philosophers(data, data->num_philosophers);
		free(data->philosophers);
	}
	if (data->forks)
	{
		i = -1;
		while (++i < data->num_philosophers)
		{
			if (pthread_mutex_destroy(&data->forks[i]) != 0)
				printf("Warning: Failed to destroy fork mutex %d\n", i);
		}
		free(data->forks);
	}
	if (pthread_mutex_destroy(&data->print_mutex) != 0)
		printf("Warning: Failed to destroy print mutex\n");
	if (pthread_mutex_destroy(&data->death_mutex) != 0)
		printf("Warning: Failed to destroy death mutex\n");
}

void	cleanup_forks(t_data *data, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&data->forks[i]);
	if (data->philosophers)
		free(data->philosophers);
	if (data->forks)
		free(data->forks);
}

void	cleanup_partial_philosophers(t_data *data, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_destroy(&data->philosophers[i].meals_eaten_) != 0)
			printf("Failed to destroy meals_eaten mutex");
		if (pthread_mutex_destroy(&data->philosophers[i].last_meal_t) != 0)
			printf("Failed to destroy last_meal_t mutex");
	}
}
