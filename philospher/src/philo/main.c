/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:42:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/24 13:55:56 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor;
	int			i;

	if (parse_data(argc, argv, &data) != 0)
		return (print_usage_instructions(), 1);
	if (init_data(&data) != 0)
		return (printf("%sInitialization failed!\n", RED), 1);
	data.start_time = get_current_time();
	if (data.start_time < 0)
		return (printf("%sCurrent time fail!\n", RED), cleanup(&data), 1);
	i = -1;
	while (++i < data.num_philosophers)
		data.philosophers[i].last_meal_time = data.start_time;
	i = -1;
	while (++i < data.num_philosophers)
	{
		if (pthread_create(&data.philosophers[i].thread, NULL, philosopher_routine, &data.philosophers[i]) != 0)
		{
			printf("%sError creating philosopher thread %d!\n", RED, i + 1);
			return (cleanup(&data), 1);
		}
	}
	if (pthread_create(&monitor, NULL, death_monitor, &data) != 0)
	{
		printf("%sError creating monitor thread!\n", RED);
		return (cleanup(&data), 1);
	}
	i = -1;
	while (++i < data.num_philosophers)
		pthread_join(data.philosophers[i].thread, NULL);
	pthread_join(monitor, NULL);
	return (cleanup(&data), printf("%sEnded successfully!\n", GREEN), 0);
}
