/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/25 18:43:40 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main sorting function
void	ft_sort(t_list **stack)
{
	t_list	*b;
	int	len;
	int chunk;
	int counter;

	b = NULL;
	chunk = 1;
	counter = 0;
	ft_printf("stack a\n");
	ft_printf("chunksize a: %d\n", ft_chunksize(*stack, 0));
	print_list(*stack);
	len = ft_lstsize(*stack); // completed
	if (len == 3)
		sort_three(stack, &counter); // completed
	else if (len == 2 && !ft_sorted(*stack))
		swap(stack, true, "sa", &counter);
	else
		recursive_push(stack, &b, len, chunk, &counter); // progress
	ft_printf("stack b\n");
	print_list(b);
	ft_printf("stack a\n");
	print_list(*stack);
	ft_printf("counter%d\n", counter);
}

// hard-coded sorting, if stack len == 3
void	sort_three(t_list **stack, int *counter)
{
	if (((*stack)->content > (*stack)->next->content) &&
		((*stack)->content > (*stack)->next->next->content))
			rotate(stack, true, "ra", counter);
	if (((*stack)->next->content > (*stack)->next->next->content) &&
		((*stack)->next->content > (*stack)->content))
		reverse_rotate(stack, true, "rra", counter);
	if((*stack)->content > (*stack)->next->content)
		swap(stack, true, "sa", counter);
}

void recursive_push(t_list **a, t_list **b, int length, int chunk, int *counter)
{
    int	mid;
    t_list *first_greater;
    int flag = 0;

    if (length <= 2) {
        if (!ft_sorted(*a)) // Sort the last two elements
            swap(a, true, "sa", counter);
        return ;
    }
	//min = Max_Min(*a, INT_MAX, 0);
	mid = findMedian(*a, 0, 35.0);
	while (*a && *a != first_greater && ft_lstsize(*a) > 3)
	{
		if ((*a)->content < mid)
		{
			(*a)->chunk = chunk;
			*counter += push(a, b, true, "pb");
		}
		else
		{
			if (!flag)
			{
				first_greater = *a;
				flag = 1;
        	}
        	rotate(a, true, "ra", counter);
        }
    }
    if (*a == first_greater && ft_lstsize(*a) > 3) {
        recursive_push(a, b, ft_lstsize(*a), chunk + 1, counter);
    } else if (!ft_sorted(*a) && ft_lstsize(*a) == 2) {
        swap(a, true, "sa", counter);
    }
	else
		sort_three(a, counter);
	print_list(*a);
    push_from_b_to_a(a, b, chunk, counter);
	// ft_printf("Counter: %d\n", counter);
}

void	push_from_b_to_a(t_list **a, t_list **b, int chunk, int *counter)
{
	int		chunk_len;
	int		mid;
	t_list	*tmp;
	// t_list	*mid;

	(void) a;
	(void) counter;
	ft_printf("PUSH to A\n");
	chunk_len = ft_chunksize(*b, chunk);
	ft_printf("chunk len: %d\n", chunk_len);
	if (chunk_len == 1)
	{
		push(b, a, true, "pa");
		return ;
	}
	while(*b && (*b)->chunk == chunk)
		*b = (*b)->next;
	(*b)->next = NULL;
	print_list(*b);
	mid = findMedian(*b, chunk, 70.0);
	tmp = find_nearest_highest(*b, chunk, mid);
	ft_printf("highest number: %d\n", tmp);
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
