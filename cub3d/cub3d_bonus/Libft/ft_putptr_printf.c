/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:13:00 by gansari           #+#    #+#             */
/*   Updated: 2024/11/26 18:13:02 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_ptr(unsigned long nbr, char *base, size_t *i)
{
	char			output;

	if (nbr >= 16)
		ft_putnbr_base_ptr(nbr / 16, base, i);
	output = base[nbr % 16];
	write(1, &output, 1);
	(*i)++;
}

void	ft_putptr_printf(void *ptr, size_t *i)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
	{
		ft_putstr_printf("(nil)", i);
		return ;
	}
	else
	{
		ft_putstr_printf("0x", i);
		ft_putnbr_base_ptr(address, "0123456789abcdef", i);
	}
}
