/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:48 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/27 12:50:50 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_param(char specifier, va_list *ptr, int *count, int *i)
{
	if (specifier == 'c')
		print_char(va_arg(*ptr, int), count);
	else if (specifier == 's')
		print_str(va_arg(*ptr, char *), count);
	else if (specifier == 'd' || specifier == 'i')
		print_nbr(va_arg(*ptr, int), count);
	else if (specifier == 'p')
		print_ptr(va_arg(*ptr, size_t), count);
	else if (specifier == 'u')
		print_uint(va_arg(*ptr, unsigned int), count);
	else if (specifier == 'x')
		print_hex(va_arg(*ptr, unsigned int), count, 'x');
	else if (specifier == 'X')
		print_hex(va_arg(*ptr, unsigned int), count, 'X');
	else if (specifier == '%')
		print_char('%', count);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			print_param(str[i], &ptr, &counter, &i);
		}
		else
			print_char(str[i], &counter);
		i++;
	}
	va_end(ptr);
	return (counter);
}
