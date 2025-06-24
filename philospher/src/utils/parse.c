/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:45:26 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/06/24 13:17:28 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosopher.h"

int	validate_data(t_data *data)
{
	if (data->num_philosophers < 2 || data->num_philosophers > 200)
		return (printf("%sNumber of philosophers must be greater than 1!\n",
				RED), 1);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (printf("%sTime values must be positive!\n", RED), 1);
	if (data->must_eat_count < 0 && data->must_eat_count != -13)
		return (printf("%sMust eat count cannot be negative!\n", RED), 1);
	return (0);
}

int	parse_data(int argc, char **argv, t_data *data)
{
	int	valid;

	valid = 1;
	if (argc < 5 || argc > 6)
		return (printf("%sIncorrect number of arguments!\n", RED), 1);
	data->num_philosophers = (int) ft_atol(argv[1], &valid);
	data->time_to_die = (long) ft_atol(argv[2], &valid);
	data->time_to_eat = (long) ft_atol(argv[3], &valid);
	data->time_to_sleep = (long) ft_atol(argv[4], &valid);
	data->must_eat_count = -13;
	if (argc == 6)
		data->must_eat_count = (int) ft_atol(argv[5], &valid);
	if (valid != 1)
		return (printf("%sNegative value is forbidden!\n", RED), 1);
	return (validate_data(data));
}
