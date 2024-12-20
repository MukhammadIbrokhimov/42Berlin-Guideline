/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:46:01 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/20 15:55:16 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push Swap.h"

void	init_nodes_a(t_list_node *a, t_list_node *b)
{
	current_index(a); // done
	current_index(b); // done
	set_target_a(a, b); // done
	cost_alanysis_a(a, b); // done
	find_cheapest(a); // done
}

void	append(t_list_node **stack, int nbr)
{
	t_list_node	*head;
	t_list_node	*last_node;

	if (!*stack || !stack)
		return ;
	head = (t_list_node *) malloc(sizeof(t_list_node));
	if (!head) return ;
	head->next = NULL;
	head->nbr = nbr;
	if (!*stack)
	{
		*stack = head;
		head->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack); // completed
		last_node->next = head;
		head->prev = last_node;
	}
}

void	current_index(t_list_node *stack)
{
	int	i;
	int	median;

	i = 0;
	median = stack_len(stack) / 2;
	while(stack)
	{
		if (i >= median)
		{
			stack->index = i;
			stack->above_median = true;
		}
		else
		{
			stack->index = i;
			stack->above_median = false;
		}
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_list_node *a, t_list_node *b)
{
	t_list_node	*target;
	t_list_node	*current_b;
	long		target_nbr;

	while (a)
	{
		current_b = b;
		target_nbr = INT_MIN;
		while (current_b)
		{
			if ((a->nbr > current_b->nbr) && (current_b->nbr > target_nbr))
			{
				target_nbr = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (target_nbr == INT_MIN)
			a->target = ft_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	MoveAtoB(t_list_node **a, t_list_node **b)
{
	t_list_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median && !cheapest_node->target->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(a, b, 'b');
	pb(b, a, false);
}

void	MoveBtoA(t_list_node **a, t_list_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

