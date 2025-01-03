/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/03 10:30:59 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// main sorting function
void	ft_sort(t_list **stack)
{
	t_list	*b;
	int		len;
	int		counter;

	b = NULL;
	counter = 0;
	len = ft_lstsize(*stack);
	index_stack(stack);
	if (len == 3)
		sort_three(stack, &counter);
	else if (len == 2 && !ft_sorted(*stack))
		swap(stack, true, "sa", &counter);
	else if (len == 4 || len == 5)
		sort_five_or_four(stack, &b, &counter);
	else
		radix_sort(stack, &b, &counter);
	// if (ft_sorted(*stack))
	// 	ft_printf("Sorted\n");
	// else
	// 	ft_printf("UnSorted\n");
	// ft_printf("counter%d\n", counter);
	// print_list(*stack);
}

void	sort_five_or_four(t_list **a, t_list **b, int *counter)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 5)
		push_minvalue(a, b, counter);
	push_minvalue(a, b, counter);
	sort_three(a, counter);
	len = ft_lstsize(*b);
	while (len--)
	{
		*counter += push(b, a, true, "pb");
		print_list(*b);
	}
}

// hard-coded sorting, if stack len == 3
void	sort_three(t_list **stack, int *counter)
{
	if (((*stack)->content > (*stack)->next->content)
		&& ((*stack)->content > (*stack)->next->next->content))
		rotate(stack, true, "ra", counter);
	if (((*stack)->next->content > (*stack)->next->next->content)
		&& ((*stack)->next->content > (*stack)->content))
		reverse_rotate(stack, true, "rra", counter);
	if ((*stack)->content > (*stack)->next->content)
		swap(stack, true, "sa", counter);
}

void	radix_sort(t_list **a, t_list **b, int *counter)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				rotate(a, true, "ra", counter);
			else
				*counter += push(a, b, true, "pb");
		}
		while (ft_lstsize(*b) != 0)
			*counter += push(b, a, true, "pa");
		i++;
	}
}
