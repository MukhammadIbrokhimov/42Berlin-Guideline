/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:11:35 by gansari           #+#    #+#             */
/*   Updated: 2024/11/26 18:11:45 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_printf(char *s, size_t *i)
{
	if (!s)
		s = ("(null)");
	while (*s)
	{
		ft_putchar_printf(*s, i);
		s++;
	}
}
