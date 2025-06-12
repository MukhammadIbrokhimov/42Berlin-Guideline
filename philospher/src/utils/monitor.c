/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:14:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/12 17:28:45 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*death_monitor(void *arg)
{
	int		i;

	t_data *data = (t_data *) arg;
	while (!simulation_ended(data))
	{
		i = -1;
		while (++i < data->num_philosophers)
		{
			pthread_mutex_lock(&data->death_mutex);
			if (is_philosopher_dead(&data->philosophers[i]))
			{
				print_status(&data->philosophers[i], "died");
				data->simulation_ended = 1;
				pthread_mutex_unlock(&data->death_mutex);
				return NULL;
			}
			pthread_mutex_unlock(&data->death_mutex);
		}
		if (all_philosophers_satisfied(data))
		{
			data->simulation_ended = 1;
			return NULL;
		}
		usleep(1000);
	}
	return NULL;
}

int	is_philosopher_dead(t_philosopher *philo)
{
	long current_time = get_current_time();
	long time_since_meal = current_time - philo->last_meal_time;
	return (time_since_meal >= philo->data->time_to_die);
}

int all_philosophers_satisfied(t_data *data)
{
	int	i;

	if (data->must_eat_count == -13) return 0;

	i = -1;
	while (++i < data->num_philosophers)
	{
		if (data->philosophers[i].meals_eaten < data->must_eat_count)
			return 0;
	}
	return 1;
}