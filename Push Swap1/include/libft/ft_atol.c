/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:28:13 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/21 19:41:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long	ft_atol(const char *s)
{
	long	number;
	int	flag;

	number = 0;
	flag = 0;
	while (ft_isspace(*s))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-' && flag == 0)
			flag--;
		else if (*s == '+' && flag == 0)
			flag++;
		else
			return (0);
		s++;
	}
	while (ft_isdigit(*s))
	{
		number = number * 10 + (*s - 48);
		s++;
	}
	if (flag < 0)
		return (-number);
	return (number);
}
