/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:47:58 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/10 20:48:33 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *monitor(void *arg)
{
	t_shared_data *shared_data = (t_shared_data *)arg;
	int i;

	while (!shared_data->simulation_ended)
	{
		for (i = 0; i < shared_data->num_philosophers; i++)
		{
			pthread_mutex_lock(&shared_data->death_mutex);
			if (shared_data->philosophers[i].last_meal_time + shared_data->time_to_die < get_current_time(shared_data->start_time))
			{
				printf("%sPhilosopher %d has died%s\n", RED, shared_data->philosophers[i].id, RESET);
				shared_data->simulation_ended = 1;
			}
			pthread_mutex_unlock(&shared_data->death_mutex);
		}
		usleep(1000); // Sleep for a short duration to avoid busy waiting
	}
	return NULL;
}