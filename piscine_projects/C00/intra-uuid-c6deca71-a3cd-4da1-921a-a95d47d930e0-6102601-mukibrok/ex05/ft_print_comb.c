/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:09:44 by mukibrok          #+#    #+#             */
/*   Updated: 2024/10/03 20:57:14 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	print_number(char *n);

/*int	main(void)
{
	ft_print_comb();
}*/

void	ft_print_comb(void)
{
	char	n[3];

	n[0] = '0';
	while (n[0] <= '7')
	{
		n[1] = n[0] + 1;
		while (n[1] <= '8')
		{
			n[2] = n[1] + 1;
			while (n[2] <= '9')
			{
				print_number(n);
				n[2]++;
			}
			n[1]++;
		}
		n[0]++;
	}
}

void	print_number(char *n)
{
	if (n[0] == '7' && n[1] == '8' && n[2] == '9')
	{
		write(1, n, 3);
	}
	else
	{
		write(1, n, 3);
		write(1, ", ", 2);
	}
}
