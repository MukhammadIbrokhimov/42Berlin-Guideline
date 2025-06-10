/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:42:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/10 20:58:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *set_activities(void *av)
{
	(void) av;
	printf("philo is generated\n");
	return (NULL);
}


void	create_philo(t_shared_data *philo)
{
	pthread_t	*phil_number = malloc(sizeof(t_philo) * philo->philo_number);
	if (!phil_number)
		return ;
	for (uint i = 0; i < philo->philo_number; i++){
		sleep(1);;
		pthread_create(&phil_number[i], NULL, set_activities, NULL);
	}

	for (uint i = 0; i < philo->philo_number; i++){
		if (pthread_join(phil_number[i], NULL) != 0)
			printf("%s%sThread Joining was unsuccessfull%s\n", RED, BOLD, RESET);
	}
}

int main(int argc, char **argv)
{

	t_shared_data	data;

	if (argc != 5 && argc != 6)
	{
		printf("%sIncorrect argument was given!\n", RED);
		print_usage_instructions();
		return (1);
	}
	if (!init_data(argc, argv, &data))
		return (print_usage_instructions(), 1);
	if (!data.num_philosophers > 0 && data.num_philosophers < 200)
	{
		printf("%sProvide with correct amount!\n", RED);
		return (1);
	}
	if (!init_philo(&data))
	{
		printf("%sMemory allocation failed!\n", RED);
		return (1);
	}
	
}
