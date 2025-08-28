/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:13:30 by gansari           #+#    #+#             */
/*   Updated: 2024/11/26 18:13:33 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunsignednbr_printf(unsigned int nb, size_t *i)
{
	unsigned int	c;

	if (nb >= 10)
		ft_putunsignednbr_printf(nb / 10, i);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	(*i)++;
}
