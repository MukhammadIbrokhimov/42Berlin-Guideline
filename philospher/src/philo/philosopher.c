/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:17:05 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/17 19:40:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;

	while (simulation_ended(philo->data) != 1)
	{
		if (eat(philo))
			break ;
		if (sleeep(philo))
			break ;
		if (think(philo))
			break ;
	}
	return (NULL);
}

int	eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
	 	precise_sleep(philo->data->time_to_eat / 2); // Ensure even philosophers wait a bit before starting
		pthread_mutex_lock(philo->left_fork);
		if (simulation_ended(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			return 1;
		}
		print_status(philo, "has taken a fork");
		//printf("DEBUG: Philosopher %d trying to get right fork %p\n", philo->id, philo->right_fork);
		pthread_mutex_lock(philo->right_fork);
		if (simulation_ended(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return 1;
		}
		print_status(philo, "has taken a fork");
	}
	else{
		pthread_mutex_lock(philo->right_fork);
		if (simulation_ended(philo->data))
		{
			pthread_mutex_unlock(philo->right_fork);
			return 1;
		}
		print_status(philo, "has taken a fork");
		//printf("DEBUG: Philosopher %d trying to get right fork %p\n", philo->id, philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		if (simulation_ended(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return 1;
		}
		print_status(philo, "has taken a fork");
	}
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
	if (philo->data->must_eat_count > 0 && 
        philo->meals_eaten >= philo->data->must_eat_count)
    {
        return 1;
    }
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