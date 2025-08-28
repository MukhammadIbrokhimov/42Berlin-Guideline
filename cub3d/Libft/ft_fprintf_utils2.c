/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:31:27 by gansari           #+#    #+#             */
/*   Updated: 2025/05/21 11:31:29 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	write_char_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	write_str_fd(char *s, int fd)
{
	int	len;

	if (!s)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, fd);
	return (len);
}

int	write_hex_digit(int digit, int uppercase, int fd)
{
	char	c;

	if (digit < 10)
		c = '0' + digit;
	else
	{
		if (uppercase)
			c = 'A' + (digit - 10);
		else
			c = 'a' + (digit - 10);
	}
	ft_putchar_fd(c, fd);
	return (1);
}

int	write_hex_fd(unsigned long n, int uppercase, int fd)
{
	int	count;
	int	tmp;

	count = 0;
	if (n >= 16)
	{
		tmp = write_hex_fd(n / 16, uppercase, fd);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	count += write_hex_digit(n % 16, uppercase, fd);
	return (count);
}

int	write_ptr_fd(void *ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		ft_putstr_fd("0x0", fd);
		return (3);
	}
	count += write_str_fd("0x", fd);
	count += write_hex_fd((unsigned long)ptr, 0, fd);
	return (count);
}
