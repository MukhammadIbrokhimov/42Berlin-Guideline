/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:42:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/24 15:47:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
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

int	start_simulation(t_data *data)
{
	pthread_t	monitor;
	int			i;

	data->start_time = get_current_time();
	i = -1;
	while (++i < data->num_philosophers)
		data->philosophers[i].last_meal_time = data->start_time;
	i = -1;
	while (++i < data->num_philosophers)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL,
				philosopher_routine, &data->philosophers[i]) != 0)
		{
			printf("%sError creating philosopher thread %d!\n", RED, i + 1);
			return (cleanup(data), 1);
		}
	}
	if (pthread_create(&monitor, NULL, death_monitor, data) != 0)
		return (printf("%sError creating monitor thread!\n", RED),
			cleanup(data), 1);
	i = -1;
	while (++i < data->num_philosophers)
		pthread_join(data->philosophers[i].thread, NULL);
	pthread_join(monitor, NULL);
	return (cleanup(data), printf("%sEnded successfully!\n", GREEN), 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_data(argc, argv, &data) != 0)
		return (print_usage_instructions(), 1);
	if (init_data(&data) != 0)
		return (printf("%sInitialization failed!\n", RED), 1);
	return (start_simulation(&data));
}
