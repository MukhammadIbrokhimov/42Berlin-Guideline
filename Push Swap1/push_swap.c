/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:22:41 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/21 20:32:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	// t_list	*b;
	int		i;

	a = NULL;
	// b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
	{
		ft_printf("./push_swap [numbers]"); // completed
		return (1);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' '); // completed
	i = 0;
	while (argv[i])
		ft_lstadd_back(&a, ft_lstnew((int) ft_atol(argv[i++])));
	if (!ft_sorted(a)) // completed
		printf("not sorted\n");
	print_list(a);
		// ft_sort(&a, &b); // progress
	ft_lstclear(&a, delete_content); // progress
}
