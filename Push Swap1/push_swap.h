/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:12:57 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/22 19:41:52 by muxammad         ###   ########.fr       */
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
void	ft_free(t_list *stack);
void	sort_three(t_list **stack);
//  initializing stack

// for testing
void	print_list(t_list *stack);
#endif
