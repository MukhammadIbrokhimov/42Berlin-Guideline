/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/17 19:41:54 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long get_current_time(void)
{
	struct timeval	tv;
	long			current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

void	precise_sleep(long milliseconds) {
	long start_time = get_current_time();
	long target_time = start_time + milliseconds;
	
	while (get_current_time() < target_time) {
		usleep(500);
	}
}

void	print_status(t_philosopher *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!simulation_ended(philo->data))
	{
		long timestamp = get_current_time() - philo->data->start_time;
		printf("%s%ld ms %sPhilosopher %d %s%s\n", CYAN, timestamp, BOLD, philo->id, status, RESET);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void print_usage_instructions()
{
	printf("%s%sUsage:\n-> %s", BOLD, RED, RESET);
	printf("%sphilospher %sgit:(%smain%s) %s✗ %s./philo 5 800 200 200 [7]%s\n",
		CYAN, BLUE, RED, BLUE, BROWN, BLUE, RESET);
}

int	simulation_ended(t_data *data)
{
	int	ended;

	pthread_mutex_lock(&data->death_mutex);
	ended = data->simulation_ended;
	pthread_mutex_unlock(&data->death_mutex);
	return (ended);
}

int check_meal_completion(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_);
	if (philo->meals_eaten >= philo->data->must_eat_count)
	{
		pthread_mutex_unlock(&philo->meals_eaten_);
		return (1);
	}
	pthread_mutex_unlock(&philo->meals_eaten_);
	return (0);
}

void	print_philo_data(t_philosopher *philo)
{
	printf("Philosopher Data:\n");
	printf("ID: %d\n", philo->id);
	printf("Meals Eaten: %d\n", philo->meals_eaten);
	printf("Last Meal Time: %ld ms\n", philo->last_meal_time);
	printf("Left Fork: %p\n", (void *)philo->left_fork);
	printf("Right Fork: %p\n", (void *)philo->right_fork);
	printf("Data Pointer: %p\n", (void *)philo->data);
}

void	print_data(t_data *data)
{
	printf("Data:\n");
	printf("Number of Philosophers: %d\n", data->num_philosophers);
	printf("Time to Die: %ld ms\n", data->time_to_die);
	printf("Time to Eat: %ld ms\n", data->time_to_eat);
	printf("Time to Sleep: %ld ms\n", data->time_to_sleep);
	printf("Must Eat Count: %d\n", data->must_eat_count);
	printf("Simulation Ended: %d\n", data->simulation_ended);
}