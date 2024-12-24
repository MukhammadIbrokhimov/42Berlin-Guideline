/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:57 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/24 00:43:24 by muxammad         ###   ########.fr       */
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

// util functions
bool	ft_sorted(t_list *stack);
bool	ft_iserror(char **argv);
bool	ft_isdouble(t_list *stack);
void	ft_free(t_list **stack);
int		Max_Min(t_list *stack, int nbr, int chunk);
int		ft_chunksize(t_list *stack, int chunk);
t_list	*find_Value(t_list *stack, int index);
//  sorting functions
void	ft_sort(t_list **a);
void	sort_three(t_list **stack);
void	recursive_push(t_list **a, t_list **b, int length, int chunk);
void	sort_three(t_list **stack);
void	push_from_b_to_a(t_list **a, t_list **b, int chunk);

// move
void	rotate(t_list **stack, bool print, char *s);
void	reverse_rotate(t_list **stack, bool print, char *s);
void	swap(t_list **stack, bool print ,char *s);
void	push(t_list **from, t_list **to, bool print, char *s);

// for testing
void	print_list(t_list *stack);
#endif
