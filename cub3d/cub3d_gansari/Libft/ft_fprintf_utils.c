/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:31:12 by gansari           #+#    #+#             */
/*   Updated: 2025/05/21 11:31:16 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(t_printf *data, int c)
{
	return (write_char_fd(c, data->fd));
}

int	print_string(t_printf *data, char *str)
{
	return (write_str_fd(str, data->fd));
}

int	print_number(t_printf *data, int num)
{
	return (write_nbr_fd(num, data->fd));
}

int	print_pointer(t_printf *data, void *ptr)
{
	return (write_ptr_fd(ptr, data->fd));
}

int	print_hex(t_printf *data, unsigned int num, int uppercase)
{
	return (write_hex_fd(num, uppercase, data->fd));
}
