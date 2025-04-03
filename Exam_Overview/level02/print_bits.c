/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:51:55 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/10 16:33:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	char	c;

	i = 7;
	while (i >= 0)
	{
		c = ((octet >> i) & 1) + 48;
		write(1, &c, 1);
		i--;
	}
}

// int	main(void)
// {
// 	print_bits(2);
// }
