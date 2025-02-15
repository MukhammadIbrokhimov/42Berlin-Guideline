/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:50:07 by mukibrok          #+#    #+#             */
/*   Updated: 2024/10/03 18:54:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

/*int	main(void)
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(100);
	write(1, "\n", 1);
	ft_putnbr(0);
}*/

void	ft_putnbr(int nb)
{
	char	n;
	long	t;

	t = nb;
	if (t < 0)
	{
		t = -t;
		write(1, "-", 1);
	}
	if (t >= 10)
	{
		ft_putnbr(t / 10);
	}
	n = (t % 10) + 48;
	write(1, &n, 1);
}
