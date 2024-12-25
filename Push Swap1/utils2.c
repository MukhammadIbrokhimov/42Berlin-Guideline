/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:53:29 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/25 18:23:53 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_nearest_highest(t_list *stack, int chunk, int mid)
{
	t_list	*highest_node;
	int	highest;

	highest = INT_MIN;
	while (stack && stack->chunk == chunk)
	{
		if (stack->content >= mid && stack->content > highest)
		{
			highest = stack->content;
			highest_node = stack;
		}
		stack = stack->next;
	}
	if (highest == INT_MIN)
	{
		while (stack && stack->chunk == chunk)
		{
			if (stack->content < mid && stack->content > highest)
			{
				highest = stack->content;
				highest_node = stack;
			}
		stack = stack->next;
		}
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
