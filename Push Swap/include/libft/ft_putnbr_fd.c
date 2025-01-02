/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:57:15 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/11 20:01:02 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln = -ln;
		ft_putchar_fd('-', fd);
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		ln %= 10;
	}
	if (ln < 10)
	{
		ft_putchar_fd(ln + 48, fd);
	}
}

// int	main(int argc, char **argv)
// {
// 	ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
// }
