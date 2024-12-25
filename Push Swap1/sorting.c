/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/24 21:58:49 by muxammad         ###   ########.fr       */
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
		reverse_rotate(stack, true, "rra");
	if((*stack)->content > (*stack)->next->content)
		swap(stack, true, "sa");
}

void recursive_push(t_list **a, t_list **b, int length, int chunk) 
{
	int	mid;
	t_list	*first_greater;
	int flag;
	
	flag = 0;
	if (length <= 2) {
		if (!ft_sorted(*a))
			swap(a, true, "sa");
		return ;
	}
	mid = findMedian(*a, 0);
	while (*a && *a != first_greater && ft_lstsize(*a) > 2)
	{
		if ((*a)->content < mid) 
		{
			(*a)->chunk = chunk;
			push(a, b, true, "pb");
		}
		else
		{
			if (!flag)
			{
				first_greater = *a;
				flag = 1;
			}
		rotate(a, true, "ra");
		}
	}
	if (*a == first_greater && ft_lstsize(*a) > 2)
		recursive_push(a, b, ft_lstsize(*a), chunk + 1);
	else if (!ft_sorted(*a))
		swap(a, true, "sa");
	push_from_b_to_a(a, b, chunk);
}

void push_from_b_to_a(t_list **a, t_list **b, int chunk)
{
	int	mid;
	int	flag;

	if (!b || !*b)
		return ;
	mid = findMedian(*b, chunk);
	flag = 0;
	while (*b && (*b)->chunk == chunk)
	{
		if ((*b)->content > mid)
		{
			push(b, a, true, "pa");
			if ((*a)->next && (*a)->content > (*a)->next->content)
				swap(a, true, "sa");
		}
		else if ((*b)->content <= mid)
		{
			rotate(b, true, "rb");
			flag += 1;
		}
	}
	
	t_list	*tail;

	tail = ft_lstlast(*b);
	while (flag > 0 && tail->chunk == chunk)
	{
		reverse_rotate(b, true, "rra");
		if (flag >= 2)
		{
			reverse_rotate(b, true, "rra");
			flag--;
		}
		if ((*b)->content < (*b)->next->content && (*b)->chunk == (*b)->next->chunk)
			swap(a, true, "sa");
		push(b, a, true, "pa");
		flag--;
	}
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
