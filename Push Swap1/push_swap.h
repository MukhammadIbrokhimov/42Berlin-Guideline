/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:57 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/25 18:24:06 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include "./include/ft_printf/ft_printf.h"
# include "./include/libft/libft.h"

bool	ft_sorted(t_list *stack);
bool	ft_iserror(char **argv);
bool	ft_isdouble(t_list *stack);
void	ft_free(t_list **stack);
int		ft_chunksize(t_list *stack, int chunk);
t_list	*find_nearest_highest(t_list *stack, int chunk, int mid);
int 	findMedian(t_list *list, int chunk, float percentile);
void 	rotate_b_chunk(t_list **b, int chunk, int *counter);
//  sorting functions
void	ft_sort(t_list **a);
void	sort_three(t_list **stack, int *counter);
void	recursive_push(t_list **a, t_list **b, int length, int chunk, int *counter);
void	push_from_b_to_a(t_list **a, t_list **b, int chunk, int *counter);

// move
void	rotate(t_list **stack, bool print, char *s, int *counter);
void	reverse_rotate(t_list **stack, bool print, char *s, int *counter);
void	swap(t_list **stack, bool print ,char *s, int *counter);
int		push(t_list **from, t_list **to, bool print, char *s);

// for testing
void	print_list(t_list *stack);
#endif
