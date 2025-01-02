/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:53:29 by muxammad          #+#    #+#             */
/*   Updated: 2025/01/02 20:58:11 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
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
		ft_printf("%d->%d->%d\n",
			stack->content, stack->chunk, stack->index);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

t_list	*ft_min(t_list	*stack)
{
	int		number;
	t_list	*min;

	number = INT_MAX;
	min = NULL;
	while (stack)
	{
		if (stack->content < number)
		{
			number = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	push_minvalue(t_list **a, t_list **b, int *counter)
{
	t_list	*min;

	min = ft_min(*a);
	while (*a != min)
	{
		if (min->index > 2)
			reverse_rotate(a, true, "rra", counter);
		else if (min->index <= 2)
			rotate(a, true, "ra", counter);
	}
	if (*a == min)
		*counter += push(a, b, true, "pa");
}
