/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:10:06 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 15:03:53 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *s)
{
	int number;

	number = 0;
	while (*s >= '0' && *s <= '9')
	{
		number *= 10;
		number += *s - 48;
		s++;
	}
	return (number);
}

int	is_prime(int num)
{
	int i;

	i = 2;
	while (i < num)
	{
		if (num % i == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	get_result(int final)
{
	int	sum;
	int	prime;
	int first;

	if (final == 1)
		write(1, "1", 1);
	prime = 2;
	first = 1;
	while (final > 1)
	{
		if (final % prime == 0)
		{
			if (!first)
				printf("*");
			printf("%d", prime);
			final /= prime;
			first = 0;
		}
		else
			prime++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		get_result(ft_atoi(argv[1]));
	printf("\n");
}
