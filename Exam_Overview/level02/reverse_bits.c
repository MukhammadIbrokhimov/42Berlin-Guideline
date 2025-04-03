/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:25:15 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/10 18:42:48 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_bits(unsigned char octet);
unsigned char	swap_bits(unsigned char octet);

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	reversed;

	int	i = 0;
	reversed = 0;
	while (i < 8)
	{
		reversed <<= 1;
		reversed |= (octet & 1);
		octet >>= 1;
		i++;
	}
	return (reversed);
}
int	main(void)
{
	unsigned char	test = '2';
	unsigned char	result = reverse_bits(test);
	unsigned char	swapped = swap_bits(result);
	print_bits(test);
	printf("%c\n", result);
	print_bits(result);
	printf("\n");
	print_bits(swapped);

}
