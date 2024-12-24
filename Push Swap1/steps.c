/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:42:04 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/24 02:28:48 by muxammad         ###   ########.fr       */
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

//void	chunk_rotate(t_list **stack, bool print, char *s, int chunk)
//{
//	t_list	*head;
//	t_list	*tail;
//	int		len;

//	len = ft_chunksize(*stack, chunk);
//	ft_printf("chunk rotate length :%d\n", len);
//	head = *stack;
//	while (*stack && (*stack)->chunk == chunk && len)
//	{
//		tail = *stack;
//		*stack = (*stack)->next;
//		len--;
//	}
//	*stack = (*stack)->next;
//	tail->next = head;
//	head->next = NULL;

//	if (print)
//		ft_printf("%s\n", s);
//}

void	reverse_rotate(t_list **stack, bool print, char *s)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	if (print)
		ft_printf("%s\n", s);
}


void	swap(t_list **stack, bool print, char *s)
{
	t_list *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (print)
		ft_printf("%s\n", s);
}

void	push(t_list **from, t_list **to, bool print, char *s)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*from) == 0)
		return ;
	head_to = *to;
	head_from = *from;
	tmp = head_from;
	head_from = head_from->next;
	*from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*to = tmp;
	}
	if (print)
		ft_printf("%s\n", s);
}
