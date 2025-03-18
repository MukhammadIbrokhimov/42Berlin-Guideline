/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:00:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/11 16:16:56 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	init_data(int argc, char **argv, t_data *philo)
{
	int	valid = 1;
	philo->philo_number = (unsigned long) ft_atol(argv[1], &valid);
	philo->timeto_die = (unsigned long) ft_atol(argv[2], &valid);
	philo->timeto_eat = (unsigned long) ft_atol(argv[3], &valid);
	philo->timeto_sleep = (unsigned long) ft_atol(argv[4], &valid);
	if (argc == 6)
		philo->dinner_number = (unsigned long) ft_atol(argv[5], &valid);
	if (valid != 1)
	{
		printf("%sNegative value is forbidden!\n", RED);
		return (false);
	}
	return (true);
}

void print_usage_instructions()
{
	printf("%s%sUsage:\n-> %s", BOLD, RED, RESET);
	printf("%sphilospher %sgit:(%smain%s) %s✗ %s./philo 5 800 200 200 [7]%s\n",
		CYAN, BLUE, RED, BLUE, BROWN, BLUE, RESET);
}