/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:22:41 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/23 02:02:35 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		return (ft_printf("./push_swap [numbers]\n"), 1);
	if (argc == 2)
		argv = ft_split(argv[1], ' '); // completed
	if (ft_iserror(argv + 1)) // completed
		return (ft_printf("Only Digit\n"), 1);
	i = 0;
	while (argv[i])
		ft_lstadd_back(&a, ft_lstnew((int) ft_atol(argv[i++])));
	if (ft_sorted(a) && !ft_isdouble(a)) // completed
		return (ft_printf("Already sorted\n", 0));
	else if (ft_isdouble(a)) // completed
		return (ft_printf("doubled number\n", 1));
	else
		ft_sort(&a, &b); // progress
	return (ft_free(&a), 0);
}
