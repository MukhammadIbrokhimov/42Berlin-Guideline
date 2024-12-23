/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/23 04:53:49 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main sorting function
void	ft_sort(t_list **stack)
{
	t_list	*b;
	int	len;

	b = (t_list *) malloc(sizeof(t_list));
	ft_printf("stack a\n");
	print_list(*stack);
	len = ft_lstsize(*stack); // completed
	if (len == 3)
		sort_three(stack); // completed
	else if (len == 2 && !ft_sorted(*stack))
		swap(stack, true, "sa");
	else
		recursive_push(stack, &b, len); // progress
	ft_printf("stack b\n");
	print_list(b);
	ft_printf("stack a\n");
	print_list(*stack);
}

// hard-coded sorting, if stack len == 3
void	sort_three(t_list **stack)
{
	if (((*stack)->content > (*stack)->next->content) &&
		((*stack)->content > (*stack)->next->next->content))
			rotate(stack, true, "ra");
	if (((*stack)->next->content > (*stack)->next->next->content) &&
		((*stack)->next->content > (*stack)->content))
		rra(stack, true);
	if((*stack)->content > (*stack)->next->content)
		swap(stack, true, "sa");
}

void	recursive_push(t_list **a, t_list **b, int length)
{
	int	max;
	int	min;
	t_list	*mid;

	if (length <= 2)
	{
		if (!ft_sorted(*a)) // completed
			swap(a, true, "sa"); // completed
		return ;
	}
	max = Max_Min(*a, INT_MIN); // completed
	min = Max_Min(*a, INT_MAX); // completed
	mid = find_Value(*a, length / 2); // completed
	if (mid->content == max || mid->content == min)
		mid = mid->prev;
	while ((*a)->content < mid->content)
	{
		push(a, b, true, "pb");	
		if ((*a)->content > mid->content)
			rotate(a, true, "ra");
	}
	if((*a)->content == mid->content)
		recursive_push(a, b, ft_lstsize(*a));
}

void	print_list(t_list *stack)
{
	if (!stack)
	{
		ft_printf("Empty");
		return ;
	}
	while (stack)
	{
		ft_printf("%d->", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}
