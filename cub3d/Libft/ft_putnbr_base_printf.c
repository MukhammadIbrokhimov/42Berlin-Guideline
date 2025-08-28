/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:13:54 by gansari           #+#    #+#             */
/*   Updated: 2024/11/26 18:13:57 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_printf(unsigned int nbr, char *base, size_t *i)
{
	char			output;

	if (nbr >= 16)
		ft_putnbr_base_printf(nbr / 16, base, i);
	output = base[nbr % 16];
	write(1, &output, 1);
	(*i)++;
}
