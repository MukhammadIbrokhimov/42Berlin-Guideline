/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:42:04 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/23 04:32:42 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, bool print, char *s)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;

	if (print)
		ft_printf("%s\n", s);
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

void	swap(t_list **stack, bool print, char *s)
{
	t_list *tmp;

	if (!*stack ||!stack)
		return ;
	tmp =(*stack)->next;
	(*stack)->next = *stack;
	*stack = tmp;
	if (print)
		ft_printf("%s\n", s);
}

void	push(t_list **from, t_list **to, bool print, char *s)
{
	t_list	*head_src;

	if (!from || !*from)
		return ;
	head_src = *from;
	*from = (*from)->next;
	(*from)->prev = NULL;
	if (!*to || !to)
	{
		*to = head_src;
		(*to)->next = NULL;
		(*to)->prev = NULL;
	}
	else
	{
		head_src->next = *to;
		(*to)->prev = head_src;
		*to = head_src;
	}
	if (print)
		ft_printf("%s\n", s);
}
