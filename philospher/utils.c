/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/06/10 19:18:27 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void print_usage_instructions()
{
	printf("%s%sUsage:\n-> %s", BOLD, RED, RESET);
	printf("%sphilospher %sgit:(%smain%s) %s✗ %s./philo 5 800 200 200 [7]%s\n",
		CYAN, BLUE, RED, BLUE, BROWN, BLUE, RESET);
}

void	print_philo(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->data.philo_number)
	{
		printf("%sPhilosopher %d:\n", BOLD, philo[i].id);
		printf("  - Left Fork: %d\n", philo[i].fork.left);
		printf("  - Right Fork: %d\n", philo[i].fork.right);
		printf("  - Time to Die: %lu ms\n", philo[i].data.timeto_die);
		printf("  - Time to Eat: %lu ms\n", philo[i].data.timeto_eat);
		printf("  - Time to Sleep: %lu ms\n", philo[i].data.timeto_sleep);
		printf("  - Dinner Number: %lu\n", philo[i].data.dinner_number);
	}
}