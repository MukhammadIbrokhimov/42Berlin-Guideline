/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_steps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:19 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/05 14:48:16 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	do_steps(t_list **a, t_list **b, char *step, int *counter)
{
	if (ft_strncmp("sa\n", step, 4) == 0)
		swap(a, false, "sa", counter);
	else if (ft_strncmp("sb\n", step, 4) == 0)
		swap(b, false, "sb", counter);
	else if (ft_strncmp("pb\n", step, 4) == 0)
		*counter += push(a, b, false, "pb");
	else if (ft_strncmp("pa\n", step, 4) == 0)
		*counter += push(b, a, false, "pa");
	else if (ft_strncmp("ra\n", step, 4) == 0)
		rotate(a, false, "ra", counter);
	else if (ft_strncmp("rb\n", step, 4) == 0)
		rotate(b, false, "rb\n", counter);
	else if (ft_strncmp("rra\n", step, 4) == 0)
		reverse_rotate(a, false, "rra", counter);
	else if (ft_strncmp("rrb\n", step, 4) == 0)
		reverse_rotate(b, false, "rrb", counter);
	else if (ft_strncmp("rrr\n", step, 4) == 0)
		rrr(a, b, counter);
	else if (ft_strncmp("rr\n", step, 4) == 0)
		rr(a, b, counter);
	else if (ft_strncmp("ss\n", step, 4) == 0)
		ss(a, b, counter);
	else
		return (ft_printf("Error\n"), 1);
	return (0);
}

void	rr(t_list **a, t_list **b, int *counter)
{
	rotate(a, false, "ra", counter);
	rotate(b, false, "rb", counter);
}

void	rrr(t_list **a, t_list **b, int *counter)
{
	reverse_rotate(a, false, "rra", counter);
	reverse_rotate(b, false, "rrb", counter);
}

void	ss(t_list **a, t_list **b, int *counter)
{
	swap(a, false, "ra", counter);
	swap(b, false, "rb", counter);
}
