/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:53:29 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/23 04:04:41 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_Value(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack && i <= index)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}