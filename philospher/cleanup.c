/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:46:26 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/10 20:47:37 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void cleanup(t_shared_data *shared_data)
{
	if (shared_data->forks)
	{
		for (int i = 0; i < shared_data->num_philosophers; i++)
			pthread_mutex_destroy(&shared_data->forks[i]);
		free(shared_data->forks);
	}
	if (shared_data->philosophers)
		free(shared_data->philosophers);
	pthread_mutex_destroy(&shared_data->print_mutex);
	pthread_mutex_destroy(&shared_data->death_mutex);
}
void cleanup_philosophers(t_philo *philos, int philo_number)
{
	if (philos)
	{
		for (int i = 0; i < philo_number; i++)
		{
			pthread_mutex_destroy(&philos[i].fork.left_fork);
			pthread_mutex_destroy(&philos[i].fork.right_fork);
		}
		free(philos);
	}
}
void cleanup_forks(pthread_mutex_t *forks, int num_forks)
{
	if (forks)
	{
		for (int i = 0; i < num_forks; i++)
			pthread_mutex_destroy(&forks[i]);
		free(forks);
	}
}
void cleanup_mutexes(pthread_mutex_t *mutex)
{
	if (mutex)
		pthread_mutex_destroy(mutex);
}