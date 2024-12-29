/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:03:39 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/29 18:44:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main sorting function
void	ft_sort(t_list **stack)
{
	t_list	*b;
	int	len;
	int	counter;
	int	chunk;

	b = NULL;
	counter = 0;
	ft_printf("stack a\n");
	ft_printf("chunksize a: %d\n", ft_chunksize(*stack, 0));
	print_list(*stack);
	len = ft_lstsize(*stack);
	chunk = 1;
	index_stack(stack);
	if (len == 3)
		sort_three(stack, &counter);
	else if (len == 2 && !ft_sorted(*stack))
		swap(stack, true, "sa", &counter);
	else if (ft_lstsize(*stack) > 100)
		radix_sort(stack, &b, &counter);
	else
		recursive_push(stack, &b, len, chunk, &counter);
	// print_list(b);
	ft_printf("stack a\n");
	print_list(*stack);
	ft_printf("stack b\n");
	print_list(b);
	if (ft_sorted(*stack))
		ft_printf("Sorted\n");
	else
		ft_printf("UnSorted\n");
	ft_printf("counter%d\n", counter);
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
	ft_printf("Counter: %d\n", *counter);
	print_list(*b);

}

void	push_from_b_to_a(t_list **a, t_list **b, int chunk, int *counter)
{
	t_list	*the_largest_among_chunk;
	int		mid;
	int		chunk_len;
	int		number_of_rotate = 0;

	if (!*b || !b)
		return;

	chunk_len = ft_chunksize(*b, chunk);
	if (chunk_len <= 2) {
		// Directly handle chunks of size 2 or less
		if (chunk_len == 2 && (*b)->content < (*b)->next->content)
			swap(b, true, "sb", counter);
		while (chunk_len--)
			*counter += push(b, a, true, "pa");
		return;
	}

	// Find median and largest element for the current chunk
	mid = find_median(*b, chunk, 75.0);
	the_largest_among_chunk = find_nearest_highest(*b, chunk, mid);

	while (chunk_len > 0) {
		if ((*b)->content > mid || *b == the_largest_among_chunk) {
			// Push larger elements to 'a'
			if ((*b)->next && (*b)->content < (*b)->next->content)
				swap(b, true, "sb", counter);
			*counter += push(b, a, true, "pa");
			if (*a && (*a)->next && (*a)->content > (*a)->next->content)
				swap(a, true, "sa", counter);
		} else {
			// Rotate smaller elements in 'b'
			rotate(b, true, "rb", counter);
			number_of_rotate++;
		}
		chunk_len--;
	}

	// After processing the chunk, reverse rotate to restore positions if necessary
	if ((*b)) {
		while (number_of_rotate > 0) {
			reverse_rotate(b, true, "rrb", counter);
			number_of_rotate--;
		}
	}

	// Recur to handle the next portion of the chunk
	push_from_b_to_a(a, b, chunk, counter);
	print_list(*b);
}

	// print_list(*b);
	// ft_printf("stack a\n");
	// // print_list(*a);
	// ft_printf("Chunk %d processed. Counter: %d\n", chunk, *counter);
	// shuf -i 0-1000 -n 100 | tr '\n' ' '
