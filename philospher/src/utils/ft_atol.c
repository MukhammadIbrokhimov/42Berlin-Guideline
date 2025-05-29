/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:28:13 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/11 16:29:41 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

unsigned long	ft_atol(const char *s, int *error)
{
	unsigned long	number;

	number = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		return ((*error = -1), 0);
	else if (*s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		number = number * 10 + (*s - '0');
		s++;
		if (number > ULONG_MAX)
			return (*error = -1, 0);
	}
	if (!ft_isdigit(*s) && *s)
		return ((*error = -1), 0);
	return (number);
}
