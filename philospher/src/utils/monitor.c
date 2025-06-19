/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:14:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/17 19:41:28 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*death_monitor(void *arg)
{
	int		i;

	//printf("DEBUG: Starting death monitor thread\n");
	t_data *data = (t_data *) arg;
	while (!simulation_ended(data))
	{
		//printf("DEBUG: Checking for dead philosophers\n");
		i = -1;
		while (++i < data->num_philosophers)
		{
			pthread_mutex_lock(&data->death_mutex);
			if (is_philosopher_dead(&data->philosophers[i]))
			{
				data->simulation_ended = 1;
				printf("%s%ld ms %sPhilosopher %d %shas died%s\n",
					CYAN, get_current_time() - data->start_time,
					BOLD, data->philosophers[i].id, RED, RESET);
				pthread_mutex_unlock(&data->death_mutex);
				//print_status(&data->philosophers[i], "died");
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
	//printf("DEBUG: Philosopher %d last meal time: %ld, current time: %ld, time since meal: %ld\n",
	//	philo->id, philo->last_meal_time, current_time, time_since_meal);
	return (time_since_meal >= philo->data->time_to_die);
}

int all_philosophers_satisfied(t_data *data)
{
	int	i;

	if (data->must_eat_count == -13)
		return (0);

	i = -1;
	while (++i < data->num_philosophers)
	{
		pthread_mutex_lock(&data->philosophers[i].meals_eaten_);
		if (data->philosophers[i].meals_eaten < data->must_eat_count)
			return 0;
		pthread_mutex_unlock(&data->philosophers[i].meals_eaten_);
	}
	return 1;
}
