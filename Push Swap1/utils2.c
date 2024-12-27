/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:53:29 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/27 15:12:33 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// hard-coded sorting, if stack len == 3
void	sort_three(t_list **stack, int *counter)
{
	if (((*stack)->content > (*stack)->next->content) &&
		((*stack)->content > (*stack)->next->next->content))
			rotate(stack, true, "ra", counter);
	if (((*stack)->next->content > (*stack)->next->next->content) &&
		((*stack)->next->content > (*stack)->content))
		reverse_rotate(stack, true, "rra", counter);
	if((*stack)->content > (*stack)->next->content)
		swap(stack, true, "sa", counter);
}

t_list	*find_nearest_highest(t_list *stack, int chunk, int mid)
{
	t_list	*highest_node;
	int		highest;

	highest = INT_MIN;
	while (stack && stack->chunk == chunk)
	{
		if (stack->content > mid && stack->content > highest)
		{
			highest = stack->content;
			highest_node = stack;
		}
		if (stack->content <= mid && stack->content > highest)
		{
			highest = stack->content;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

int	ft_chunksize(t_list *stack, int chunk)
{
	int	i;

	i = 0;
	while (stack && stack->chunk == chunk)
	{
		i++;
		stack = stack->next;
	}
	return (i);
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
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}
