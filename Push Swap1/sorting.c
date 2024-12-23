/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/23 20:27:01 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main sorting function
void	ft_sort(t_list **stack)
{
	t_list	*b;
	int	len;
	int chunk;

	b = NULL;
	chunk = 1;
	ft_printf("stack a\n");
	print_list(*stack);
	len = ft_lstsize(*stack); // completed
	if (len == 3)
		sort_three(stack); // completed
	else if (len == 2 && !ft_sorted(*stack))
		swap(stack, true, "sa");
	else
		recursive_push(stack, &b, len, chunk); // progress
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

void	recursive_push(t_list **a, t_list **b, int length, int chunk)
{
	int	min;
	t_list	*mid;
	t_list	*first_greater;
	int	flag;

	if (length <= 2)
	{
		if (!ft_sorted(*a)) // completed
			swap(a, true, "sa"); // completed
		return ;
	}
	min = Max_Min(*a, INT_MAX); // completed
	ft_printf("length %d\n", length);
	mid = find_Value(*a, (length - 2) / 2); // completed
	ft_printf("mid_value %d\n", mid->content);
	if (mid->content == min)
		mid = mid->prev;
	ft_printf("mid_value %d\n", mid->content);
	flag = 0;
	while (*a && *a != first_greater && ft_lstsize(*a) > 2)
	{
		if ((*a)->content < mid->content)
		{
			(*a)->chunk = chunk;
			push(a, b, true, "pb");
		}
		if ((*a)->content >= mid->content)
		{
			if (!flag)
			{
				first_greater = *a;
				flag = 1;	
			}
			ft_printf("first greater: %d\n", first_greater->content);
			rotate(a, true, "ra");
		}
	}
	ft_printf("loop finished and recursion started");
	print_list(*a);
	if(*a == first_greater && ft_lstsize(*a) > 2)
		recursive_push(a, b, ft_lstsize(*a), chunk + 1);
	else if (!(ft_sorted(*a)))
		swap(a, true, "sa");
	push_from_b_to_a()
	
}

void	push_from_b_to_a(t_list **a, t_list **b, int chunk)
{
	
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
		ft_printf("%d->%d\n", stack->content, stack->chunk);
		stack = stack->next;
	}
	ft_printf("\n");
}
