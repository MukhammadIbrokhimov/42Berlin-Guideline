/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/26 15:16:33 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

long	get_current_time(void)
{
	struct timeval	tv;
	long			current_time;

	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

void	precise_sleep(long milliseconds)
{
	long	start_time;
	long	target_time;

	start_time = get_current_time();
	target_time = start_time + milliseconds;
	while (get_current_time() < target_time)
		usleep(500);
}

void	print_status(t_philosopher *philo, const char *status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!simulation_ended(philo->data))
	{
		timestamp = get_current_time() - philo->data->start_time;
		printf("%s%ld ms %sPhilosopher %d %s%s\n",
			CYAN, timestamp, BOLD, philo->id, status, RESET);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	simulation_ended(t_data *data)
{
	int	ended;

	pthread_mutex_lock(&data->death_mutex);
	ended = data->simulation_ended;
	pthread_mutex_unlock(&data->death_mutex);
	return (ended);
}

void	print_usage_instructions(void)
{
	printf("%s%sUsage:\n-> %s", BOLD, RED, RESET);
	printf("%sphilospher %sgit:(%smain%s) %s✗ %s./philo 5 800 200 200 [7]%s\n",
		CYAN, BLUE, RED, BLUE, BROWN, BLUE, RESET);
}
