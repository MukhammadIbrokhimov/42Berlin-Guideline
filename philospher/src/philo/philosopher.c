/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:05 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/12 17:16:12 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;

	if (philo->id % 2 == 0)
		precise_sleep(philo->data->time_to_eat / 2);
	while (!simulation_ended(philo->data))
	{
		eat(philo);
		if (check_meal_completion(philo))
			break ;
		sleeep(philo);
		think(philo);
	}
	return NULL;
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a left fork");
	if (simulation_ended(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a right fork");

	philo->last_meal_time = get_current_time();
	print_status(philo, "is eating");
	precise_sleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleeep(t_philosopher *philo)
{
	print_status(philo, "is sleeping");
	precise_sleep(philo->data->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	print_status(philo, "is thinking");
}