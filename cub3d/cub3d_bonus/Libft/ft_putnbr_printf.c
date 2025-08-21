/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:10:59 by gansari           #+#    #+#             */
/*   Updated: 2024/11/26 18:11:04 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf(int nb, size_t *i)
{
	long	c;
	long	num;

	num = (long)nb;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		(*i)++;
	}
	if (num >= 10)
		ft_putnbr_printf(num / 10, i);
	c = (num % 10) + '0';
	write(1, &c, 1);
	(*i)++;
}
