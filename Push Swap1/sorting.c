/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/22 19:35:37 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main sorting function
void	ft_sort(t_list **a, t_list **b)
{
	t_list	*tmp;
	if (ft_lstsize(*a) == 3)
		ft_three(a);
}

// hard-coded sorting, if stack len == 3
void	sort_three(t_list **stack)
{
	if (((*stack)->content > (*stack)->next->content) &&
		((*stack)->content > (*stack)->next->next->content))
			ra(stack, true);
	if (((*stack)->next->content > (*stack)->next->next->content) &&
		((*stack)->next->content > (*stack)->content))
		rra(stack, true);
	if((*stack)->content > (*stack)->next->content)
		sa(stack, true);
}

void	print_list(t_list *stack)
{
	while (stack)
	{
		printf("%d->", stack->content);
		stack = stack->next;
	}
}
