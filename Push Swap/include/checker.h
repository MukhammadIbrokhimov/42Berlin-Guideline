/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 10:18:19 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/05 09:12:49 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include "push_swap.h"
# include "../bonus/get_nextline/get_next_line.h"

int		do_steps(t_list **a, t_list **b, char *step, int *counter);
void	print_list(t_list *stack);
void	ss(t_list **a, t_list **b, int *counter);
void	rrr(t_list **a, t_list **b, int *counter);
void	rr(t_list **a, t_list **b, int *counter);

#endif