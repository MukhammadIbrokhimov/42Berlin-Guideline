/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:18:19 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/04 18:15:56 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER

# define CHECKER

# include "push_swap.h"
# include "../bonus/get_nextline/get_next_line.h"

int		do_steps(t_list **a, t_list **b, char *step, int *counter);
void	print_list(t_list *stack);
void	ss(t_list **a, t_list **b, int *counter);
void	rrr(t_list **a, t_list **b, int *counter);
void	rr(t_list **a, t_list **b, int *counter);

#endif
