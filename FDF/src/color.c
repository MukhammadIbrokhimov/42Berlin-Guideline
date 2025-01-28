/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 19:40:45 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

unsigned int get_color(int z1, int z2)
{
	float min_height = -30.0;
	float max_height = 80.0;
	float norm1 = (z1 - min_height) / (max_height - min_height);
	float norm2 = (z2 - min_height) / (max_height - min_height);
	float blended = (norm1 + norm2) / 2.0;
	int red   = (int)(blended * 255);
	int green = (int)((1 - blended) * 255);
	int blue  = 150;
	return ((red << 16) | (green << 8) | blue);
}

void put_pixel_big(fdf *data, int x, int y)
{
	char *addr;
	int pixel;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		addr = data->address_data;
		pixel = y * data->size_line + x * 4;
		data->color = get_color(data->side.z1, data->side.z2);

		addr[pixel + 0] = (data->color >> 0) & 255;
		addr[pixel + 1] = (data->color >> 8) & 255;
		addr[pixel + 2] = (data->color >> 16) & 255;
		addr[pixel + 3] = (data->color >> 24) & 255;
	}
}

void put_pixel_less(fdf *data, int x, int y)
{
	char *addr;
	int pixel;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		addr = data->address_data;
		pixel = y * data->size_line + x * 4;
		data->color = get_color(data->side.z1, data->side.z2);
		addr[pixel + 0] = (data->color >> 0) & 255;
		addr[pixel + 1] = (data->color >> 8) & 255;
		addr[pixel + 2] = (data->color >> 16) & 255;
		addr[pixel + 3] = (data->color >> 24) & 255;
	}
}