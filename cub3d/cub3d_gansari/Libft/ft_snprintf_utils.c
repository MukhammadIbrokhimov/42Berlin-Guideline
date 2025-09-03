/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:25:40 by gansari           #+#    #+#             */
/*   Updated: 2025/04/28 12:25:42 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_snprintf(int nb, t_snprintf_data *data)
{
	long	num;

	num = (long)nb;
	if (num < 0)
	{
		ft_putchar_snprintf('-', data);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_snprintf(num / 10, data);
	ft_putchar_snprintf((num % 10) + '0', data);
}

void	ft_putunsignednbr_snprintf(unsigned int nb, t_snprintf_data *data)
{
	if (nb >= 10)
		ft_putunsignednbr_snprintf(nb / 10, data);
	ft_putchar_snprintf((nb % 10) + '0', data);
}

void	ft_putnbr_base_snprintf(unsigned int nbr, char *base,
								t_snprintf_data *data)
{
	if (nbr >= 16)
		ft_putnbr_base_snprintf(nbr / 16, base, data);
	ft_putchar_snprintf(base[nbr % 16], data);
}

void	ft_putnbr_base_ptr_snprintf(unsigned long nbr, char *base,
									t_snprintf_data *data)
{
	if (nbr >= 16)
		ft_putnbr_base_ptr_snprintf(nbr / 16, base, data);
	ft_putchar_snprintf(base[nbr % 16], data);
}

void	ft_putptr_snprintf(void *ptr, t_snprintf_data *data)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
		ft_putstr_snprintf("(nil)", data);
	else
	{
		ft_putstr_snprintf("0x", data);
		ft_putnbr_base_ptr_snprintf(address, "0123456789abcdef", data);
	}
}
