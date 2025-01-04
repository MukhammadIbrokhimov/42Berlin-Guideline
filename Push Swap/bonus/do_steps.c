/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_steps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:36:19 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/04 18:40:47 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	do_steps(t_list **a, t_list **b, char *step, int *counter)
{
	if (ft_strcmp(step, "sa") == 0)
		swap(a, false, "sa", counter);
	else if (ft_strcmp("sb", step) == 0)
		swap(b, false, "sb", counter);
	else if (ft_strcmp("pb", step) == 0)
		*counter += push(a, b, false, "pb");
	else if (ft_strcmp("pa", step) == 0)
		*counter += push(b, a, false, "pa");
	else if (ft_strcmp("ra", step) == 0)
		rotate(a, false, "ra", counter);
	else if (ft_strcmp("rb", step) == 0)
		rotate(b, false, "rb", counter);
	else if (ft_strcmp("rra", step) == 0)
		reverse_rotate(a, false, "rra", counter);
	else if (ft_strcmp("rrb", step) == 0)
		reverse_rotate(b, false, "rrb", counter);
	else if (ft_strcmp("rrr", step) == 0)
		rrr(a, b, counter);
	else if (ft_strcmp("rr", step) == 0)
		rr(a, b, counter);
	else if (ft_strcmp("ss", step) == 0)
		ss(a, b, counter);
	else
		return (ft_printf("Error\n"), 1);
	return (0);
}

void	print_list(t_list *stack)
{
	if (!stack)
	{
		ft_printf("Empty\n");
		return ;
	}
	while (stack)
	{
		ft_printf("%d->%d\n",
			stack->content, stack->index);
		stack = stack->next;
	}
	ft_printf("\n");
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
