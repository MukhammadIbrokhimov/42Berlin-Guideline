/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/17 13:43:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int get_color(int z1, int z2)
{
	float min_height = -30.0;
	float max_height = 80.0;

	// Normalize both heights
	float norm1 = (z1 - min_height) / (max_height - min_height);
	float norm2 = (z2 - min_height) / (max_height - min_height);

	// Blend the two heights (simple average)
	float blended = (norm1 + norm2) / 2.0;

	// Calculate RGB values
	int red   = (int)(blended * 255);
	int green = (int)((1 - blended) * 255);
	int blue  = 150; // Fixed blue tone

	return ((red << 16) | (green << 8) | blue);
}


unsigned int	white_on_black(int h)
{
	(void)h;
	return (0xFFFFFF);
}