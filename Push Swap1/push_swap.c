/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:22:41 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/29 14:05:27 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **argv)
{
	t_list	*a;
	int		i;
	int		flag;

	i = 0;
	a = NULL;
	while (argv[i])
		ft_lstadd_back(&a, ft_lstnew((int) ft_atol(argv[i++], &flag)));
	if (ft_sorted(a) || ft_isdouble(a) || !flag)
	{
		ft_free(&a);
		return (ft_printf("Error\n", 1));
	}
	else
		ft_sort(&a);
	return (ft_free(&a), 0);
}

int	main(int argc, char **argv)
{
	char	**arr;

	if (argc < 2 || argv[1][0] == '\0')
		return (-1);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (ft_iserror(arr))
			return (ft_printf("Error\n"), ft_free_arr(arr), 1);
		push_swap(arr);
		ft_free_arr(arr);
	}
	else
	{
		if (ft_iserror(argv + 1))
			return (ft_printf("Error\n"), 1);
		push_swap(argv + 1);
	}
	return (0);
}
