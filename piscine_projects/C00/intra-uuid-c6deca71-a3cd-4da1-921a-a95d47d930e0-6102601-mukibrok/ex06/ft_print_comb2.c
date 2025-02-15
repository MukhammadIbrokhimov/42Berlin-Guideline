/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:01:11 by mukibrok          #+#    #+#             */
/*   Updated: 2024/10/03 21:00:27 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(int n);
void	ft_print_comb2(void);

/*int	main(void)
{
	ft_print_comb2();
}*/

void	ft_print_comb2(void)
{
	int	col[2];

	col[0] = 0;
	while (col[0] <= 98)
	{
		col[1] = col[0] + 1;
		while (col[1] <= 99)
		{
			print_number(col[0]);
			write(1, " ", 1);
			print_number(col[1]);
			if (col[0] == 98 && col[1] == 99)
			{
				write(1, "", 1);
			}
			else
			{
				write(1, ", ", 2);
			}
			col[1]++;
		}
		col[0]++;
	}
}

void	print_number(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, "0", 1);
		write(1, &c, 1);
	}
	else
	{
		c = n / 10 + 48;
		write(1, &c, 1);
		c = (n % 10) + 48;
		write(1, &c, 1);
	}
}
