/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:04:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/04 12:23:51 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

ft_init_list(char **str)
{
	t_list	*a;
	int		i;
	int		*flag;

	a = NULL;
	i = 0;
	flag = 0;
	while (str[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atol(str[i++], &flag)));
	if (ft_isdouble(a) || flag == -1)
		return (ft_free(&a), ft_printf("Error\n"), -1);


}

int	main(int argc, char **argv)
{
	char	**arr;

	arr = NULL;
	if (argv < 2 || !argv[1][0])
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' '); // completed
		if (ft_iserror(arr))
			return (ft_free_arr(arr), ft_printf("Error\n"), -1);
		ft_init_list(arr); // progress
	}
	else
		ft_init_list(argv + 1); // progress
	ft_free_arr(arr);
}
