/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:59:27 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/10 21:09:28 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_philo(t_shared_data *data)
{
	uint	i;

	data->philosophers = malloc(sizeof(t_shared_data) * data->num_philosophers);
	if (!data->philosophers)
		return (1);
	i = -1;
	while (++i < data->num_philosophers)
	{
		(data->philosophers)[i].id = i + 1;
		(data->philosophers)[i].data = data;
		(data->philosophers)[i].fork.left_fork = i;
		(data->philosophers)[i].fork.right_fork = (i + 1) % data->num_philosophers;
	}
	return (true);
}

int	init_data(int argc, char **argv, t_shared_data *philo)
{
	int	valid = 1;
	philo->num_philosophers = (unsigned long) ft_atol(argv[1], &valid);
	philo->time_to_die = (unsigned long) ft_atol(argv[2], &valid);
	philo->time_to_eat = (unsigned long) ft_atol(argv[3], &valid);
	philo->time_to_sleep = (unsigned long) ft_atol(argv[4], &valid);
	philo->simulation_ended = 0;
	if (argc == 6)
		philo->must_eat_count = (unsigned long) ft_atol(argv[5], &valid);
	if (valid != 1)
	{
		printf("%sNegative value is forbidden!\n", RED);
		return (false);
	}
	return (true);
}