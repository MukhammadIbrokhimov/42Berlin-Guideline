/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/24 20:41:41 by muxammad         ###   ########.fr       */
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
    int mid;
	//int	min;
    t_list *first_greater;
    int flag = 0;

    if (length <= 2) {
        if (!ft_sorted(*a)) // Sort the last two elements
            swap(a, true, "sa");
        return;
    }

	//min = Max_Min(*a, INT_MAX, 0);
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

    if (*a == first_greater && ft_lstsize(*a) > 2) {
        recursive_push(a, b, ft_lstsize(*a), chunk + 1);
    } else if (!ft_sorted(*a)) {
        swap(a, true, "sa");
    }
    push_from_b_to_a(a, b, chunk);
}


void push_from_b_to_a(t_list **a, t_list **b, int chunk)
{
    int min;
	int flag;

    if (!b || !*b)
        return;

    min = Max_Min(*b, INT_MAX, chunk);
	flag = 0;
    while (*b && (*b)->chunk == chunk) {
        if ((*b)->content > min) {
            push(b, a, true, "pa");
            if ((*a)->next && (*a)->content > (*a)->next->content) {
                swap(a, true, "sa");
            }
        } else if ((*b)->content == min)
		{
            push(b, a, true, "rb");
			if (*a)
				rotate(a, true, "rra");
			flag = 1;
        }
    }
	if (flag)
		reverse_rotate(a, true, "rra");
    // Push the minimum element last
    //while (*b && (*b)->content == min && (*b)->chunk == chunk) {
    //    push(b, a, true, "pa");
    //    rotate(a, true, "ra");
    //}
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
