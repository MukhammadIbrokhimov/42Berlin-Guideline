/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:37:18 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/10 19:09:17 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	left_half = octet & 0xF0;
	unsigned char	right_half = octet & 0x0F;
	unsigned char	swapped = (left_half >> 4) | (right_half << 4);
	return (swapped);
}
