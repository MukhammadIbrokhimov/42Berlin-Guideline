/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/27 17:13:07 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main sorting function
void	ft_sort(t_list **stack)
{
	t_list	*b;
	int	len;
	int	chunk;
	int	counter;

	b = NULL;
	chunk = 1;
	counter = 0;
	// ft_printf("stack a\n");
	// ft_printf("chunksize a: %d\n", ft_chunksize(*stack, 0));
	// print_list(*stack);
	len = ft_lstsize(*stack);
	if (len == 3)
		sort_three(stack, &counter);
	else if (len == 2 && !ft_sorted(*stack))
		swap(stack, true, "sa", &counter);
	else
		recursive_push(stack, &b, len, chunk, &counter);
	ft_printf("stack b\n");
	print_list(b);
	// ft_printf("stack a\n");
	print_list(*stack);
	// print_list(b);
	if (ft_sorted(*stack))
		ft_printf("Sorted\n");
	else
		ft_printf("UnSorted\n");
	ft_printf("counter%d\n", counter);
}

void recursive_push(t_list **a, t_list **b, int length, int chunk, int *counter)
{
    int	mid = 0;;
    t_list *first_greater = NULL;
    int flag = 0;

    if (length <= 2) {
        if (!ft_sorted(*a)) // Sort the last two elements
            swap(a, true, "sa", counter);
        return ;
    };
	//min = Max_Min(*a, INT_MAX, 0);
	mid = find_median(*a, 0, 25.0);
	ft_printf("mid number%d\n", mid);
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
	ft_printf("Counter: %d\n", &counter);
}

void	push_from_b_to_a(t_list **a, t_list **b, int chunk, int *counter)
{
	t_list	*current;
	t_list	*chunk_end;
	t_list	*first_smaller;
	int		mid;
	int		chunk_len;
	int		flag;

	ft_printf("PUSH to A\n");
	chunk_len = ft_chunksize(*b, chunk);
	ft_printf("chunk len: %d\n", chunk_len);
	print_list(*b);
	if (chunk_len <= 2)
	{
		if (chunk_len == 2 && (*b)->content < (*b)->next->content)
			swap(b, true, "sb", counter);
		if (chunk_len == 2)
			*counter += push(b, a, true, "pa");
		*counter += push(b, a, true, "pa");
		return ;
	}
	if (!*b || !b)
		return ;
	current = *b;
	while (current && current->chunk == chunk)
	{
		chunk_end = current;
		current = current->next;
	}
	if (chunk_end)
		chunk_end->next = NULL;
	ft_printf("affter division\n");
	print_list(*b);
	mid = find_median(*b, chunk, 85.0);
	flag = 1;
	while (*b && (*b)->chunk == chunk) {
		if (*b == first_smaller)
		{
			if (*b == first_smaller)
				flag = 1;
			*counter += push(b, a, true, "pa");
			if ((*a)->content > (*a)->next->content)
				swap(a, true, "sa", counter);
		}
		if (flag)
		{
			first_smaller = find_nearest_highest(*b, chunk, mid);
			ft_printf("first_smaller: %d\n", first_smaller->content);
			flag = 0;
		}
		else
			rotate(b, true, "rb", counter);
	}
	if (current)
		*b = current;
	else
		*b = NULL;
	// print_list(*b);
	// ft_printf("stack a\n");
	// // print_list(*a);
	// ft_printf("Chunk %d processed. Counter: %d\n", chunk, *counter);
	// shuf -i 0-1000 -n 100 | tr '\n' ' '
}
