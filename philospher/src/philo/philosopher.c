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

	 if (philo->id % 2 == 0)
	 	precise_sleep(philo->data->time_to_eat / 2); // Ensure even philosophers wait a bit before starting
	//printf("DEBUG: Philosopher %d starting routine\n", philo->id);
	while (simulation_ended(philo->data) != 1)
	{
		//printf("DEBUG: Philosopher %d is starting to eat\n", philo->id);
		if (!eat(philo))
			break ;
		//printf("DEBUG: Philosopher %d finished eating\n", philo->id);
		if (check_meal_completion(philo))
			break ;
		//printf("DEBUG: Philosopher %d is going to sleep\n", philo->id);
		if (!sleeep(philo))
			break ;
		//printf("DEBUG: Philosopher %d finished sleeping\n", philo->id);
		//printf("DEBUG: Philosopher %d is thinking\n", philo->id);
		if (think(philo))
			break ;
		//printf("DEBUG: Philosopher %d finished thinking\n", philo->id);
	}
	return NULL;
}

int	eat(t_philosopher *philo)
{
	//printf("DEBUG: Philosopher %d trying to get left fork %p\n", philo->id, philo->left_fork);
	pthread_mutex_lock(philo->left_fork);
	if (simulation_ended(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		return 1;
	}
	print_status(philo, "has taken a left fork");
	//printf("DEBUG: Philosopher %d trying to get right fork %p\n", philo->id, philo->right_fork);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a right fork");
	philo->last_meal_time = get_current_time();
	print_status(philo, "is eating");
	if (simulation_ended(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return 1;
	}
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
	//usleep(500); // Ensure a slight delay before sleeping
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
	//usleep(500); // Ensure a slight delay before thinking
	print_status(philo, "is thinking");
	return (0);
}