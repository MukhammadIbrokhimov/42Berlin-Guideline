/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:42:04 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/23 02:08:57 by muxammad         ###   ########.fr       */
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

	if (!stack || !*stack)
		return ;
	head = *stack;
	tail = ft_lstlast(*stack);
	tail->next = head;
	tail->prev->next = NULL;
	tail->prev = NULL;
	*stack = tail;
	if (print)
		ft_printf("rra\n");
}

void	sa(t_list **stack, bool print)
{
	t_list *tmp;

	if (!*stack ||!stack)
		return ;
	tmp =(*stack)->next;
	(*stack)->next = *stack;
	*stack = tmp;
	if (print)
		ft_printf("sa\n");
}