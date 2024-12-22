/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:42:04 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/22 20:23:05 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack, bool print)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;

	if (print)
		ft_printf("ra\n");
}

void	rra(t_list **stack, bool print)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(*stack);
	tail->next = head;
	*stack = tail;
	tail->prev->next = NULL;
	if (print)
		ft_printf("rra\n");
}

void	sa(t_list **stack, bool print)
{
	t_list *tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	if (print)
		ft_printf("sa\n");
}