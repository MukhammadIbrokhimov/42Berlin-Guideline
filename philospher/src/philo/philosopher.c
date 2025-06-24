/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:05 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/24 15:35:40 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	take_forks(t_philosopher *philo, t_mutex *first, t_mutex *second)
{
	pthread_mutex_lock(first);
	if (simulation_ended(philo->data))
		return (pthread_mutex_unlock(first), 1);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second);
	if (simulation_ended(philo->data))
	{
		pthread_mutex_unlock(first);
		pthread_mutex_unlock(second);
		return (1);
	}
	print_status(philo, "has taken a fork");
	return (0);
}

void	set_fork_order(t_philosopher *philo, t_mutex **first, t_mutex **second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
}

int	eat(t_philosopher *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id % 2 == 0)
		precise_sleep(philo->data->time_to_eat / 2);
	set_fork_order(philo, &first_fork, &second_fork);
	if (take_forks(philo, first_fork, second_fork))
		return (1);
	pthread_mutex_lock(&philo->last_meal_t);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->last_meal_t);
	print_status(philo, "is eating");
	precise_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->meals_eaten_);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	sleeep(t_philosopher *philo)
{
	if (simulation_ended(philo->data))
		return (1);
	print_status(philo, "is sleeping");
	precise_sleep(philo->data->time_to_sleep);
	return (0);
}

int	think(t_philosopher *philo)
{
	if (simulation_ended(philo->data))
		return (1);
	print_status(philo, "is thinking");
	return (0);
}
