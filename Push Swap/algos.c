/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:40:52 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/22 19:31:39 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push Swap.h"

void	sort_three(t_list_node **stack)
{
	if (((*stack)->nbr > (*stack)->next->nbr) &&
		((*stack)->nbr > (*stack)->next->next->nbr))
			ra(stack, false);
	if (((*stack)->next->nbr > (*stack)->next->next->nbr) &&
		((*stack)->next->nbr > (*stack)->nbr))
		rra(stack, false);
	if((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}


// t_list_node *create_node(int value)
// {
//     t_list_node *new_node = malloc(sizeof(t_list_node));
//     if (!new_node)
//     {
//         perror("Error allocating memory");
//         exit(EXIT_FAILURE);
//     }
//     new_node->nbr = value;
//     new_node->next = NULL;
//     return new_node;
// }

// // Function to print the stack
// void print_stack(t_list_node *stack)
// {
//     while (stack)
//     {
//         printf("%d -> ", stack->nbr);
//         stack = stack->next;
//     }
//     printf("NULL\n");
// }

// // Main function to test sort_three
// int main()
// {
//     // Create a stack with 3 nodes
//     t_list_node *stack = create_node(43);
// 	t_list_node *dst = NULL;
//     stack->next = create_node(21);
//     stack->next->next = create_node(32);

//     printf("Before sorting:\n");
//     print_stack(stack);

//     // Sort the stack
//     sort_three(&stack);

//     printf("After sorting:\n");
//     print_stack(stack);

// 	//push from a to b;
// 	push(&stack, &dst, "pa");
// 	push(&stack, &dst, "pa");
// 	push(&stack, &dst, "pa");
// 	// push(&stack, &dst, "pa");
// 	print_stack(dst);
// 	printf("stack after push\n");
// 	print_stack(stack);

//     // Free the stack
//     t_list_node *tmp;
//     while (stack)
//     {
//         tmp = stack;
//         stack = stack->next;
//         free(tmp);
//     }

//     return 0;
// }
