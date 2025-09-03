/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:10:40 by gansari           #+#    #+#             */
/*   Updated: 2024/11/26 18:10:44 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_typecheck(va_list args, char *str, size_t *i)
{
	if (*str == 'c')
		ft_putchar_printf(va_arg(args, int), i);
	else if (*str == 's')
		ft_putstr_printf(va_arg(args, char *), i);
	else if (*str == 'd')
		ft_putnbr_printf(va_arg(args, int), i);
	else if (*str == 'i')
		ft_putnbr_printf(va_arg(args, int), i);
	else if (*str == 'x')
		ft_putnbr_base_printf(va_arg(args, int), ("0123456789abcdef"), i);
	else if (*str == 'X')
		ft_putnbr_base_printf(va_arg(args, int), ("0123456789ABCDEF"), i);
	else if (*str == 'u')
		ft_putunsignednbr_printf(va_arg(args, long), i);
	else if (*str == 'p')
		ft_putptr_printf(va_arg(args, void *), i);
	else if (*str == '%')
		ft_putchar_printf(*str, i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_typecheck(args, (char *)str, &i);
		}
		else
			ft_putchar_printf(*str, &i);
		str++;
	}
	va_end(args);
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char nb = 'a';
// 	// printf(" %p %p ", INT_MAX, INT_MIN);
// 	printf("\n");
// 	ft_printf(" %p", &nb);
// 	printf("\n");
// 	printf(" %p", &nb);
// 	return (0);
// }
