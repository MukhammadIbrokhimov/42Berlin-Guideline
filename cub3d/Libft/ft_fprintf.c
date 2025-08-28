/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:31:46 by gansari           #+#    #+#             */
/*   Updated: 2025/05/21 11:31:48 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_conversion(t_printf *data, char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(data, va_arg(args, int)));
	else if (specifier == 's')
		return (print_string(data, va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_number(data, va_arg(args, int)));
	else if (specifier == 'p')
		return (print_pointer(data, va_arg(args, void *)));
	else if (specifier == 'x')
		return (print_hex(data, va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex(data, va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (write_char_fd('%', data->fd));
	return (0);
}

int	parse_format(t_printf *data, const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_conversion(data, format[i], args);
		}
		else
			count += write_char_fd(format[i], data->fd);
		i++;
	}
	return (count);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_printf	data;
	int			ret;

	if (!format)
		return (-1);
	va_start(args, format);
	ft_bzero(&data, sizeof(t_printf));
	data.fd = fd;
	ret = parse_format(&data, format, args);
	va_end(args);
	return (ret);
}
