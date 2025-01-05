/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:04:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/05 09:09:09 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_init_list(char **str, int *counter)
{
	t_list	*a;
	t_list	*b;
	char	*steps;
	int		i;
	int		flag;

	a = NULL;
	b = NULL;
	i = 0;
	flag = 0;
	while (str[i])
		ft_lstadd_back(&a, ft_lstnew((int) ft_atol(str[i++], &flag)));
	if (ft_isdouble(a) || (flag == -1))
		return (ft_free(&a), ft_printf("Error\n"), -1);
	steps = get_next_line(0);
	while (steps)
	{
		if (do_steps(&a, &b, steps, counter))
			return (free(steps), ft_free(&a), ft_free(&b), -1);
		free(steps);
		steps = get_next_line(0);
	}
	if (ft_sorted(a))
		return (ft_printf("OK\n"), ft_free(&a), ft_free(&b), 0);
	return (ft_printf("KO\n"), ft_free(&a), ft_free(&b), 0);
}

int	main(int argc, char **argv)
{
	char	**arr;
	int		counter;

	counter = 0;
	arr = NULL;
	if (argc < 2 || !argv[1][0])
		return (-1);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (ft_iserror(arr))
			return (ft_free_arr(arr), ft_printf("Error\n"), -1);
		ft_init_list(arr, &counter);
	}
	else
	{
		if (ft_iserror(argv + 1))
			return (ft_printf("Error\n"), -1);
		ft_init_list(argv + 1, &counter);
	}
	ft_free_arr(arr);
}
