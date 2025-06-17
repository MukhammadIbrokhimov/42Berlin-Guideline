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

void	cleanup(t_data *data)
{
	int	i;

	if (data->philosophers)
	{
		i = -1;
		while (++i < data->num_philosophers)
		{
			pthread_mutex_destroy(data->philosophers[i].left_fork);
			pthread_mutex_destroy(data->philosophers[i].right_fork);
			pthread_mutex_destroy(&data->philosophers[i].meals_eaten_);
			pthread_mutex_destroy(&data->philosophers[i].last_meal_t);
		}
		free(data->philosophers);
	}
	if (data->forks)
	{
		for (i = 0; i < data->num_philosophers; i++)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
}