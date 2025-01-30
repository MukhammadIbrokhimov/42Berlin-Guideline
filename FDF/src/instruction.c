/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:24:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/30 18:26:13 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void put_pixel_to_img(fdf *data, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->address_data + (y * data->size_line + x * (data->b_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// Function to draw the usage panel in the image
void draw_usage(fdf *data)
{
	int x, y;

	// Fill the right section with a gray background
	for (y = 0; y < WIN_HEIGHT; y++)
	{
		for (x = WIN_WIDTH - USAGE_WIDTH; x < WIN_WIDTH; x++)
			put_pixel_to_img(data, x, y, data->color);
	}

	// Display usage instructions using mlx_string_put()
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 50, 0x000000, "Usage:");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 80, 0x000000, "WASD - Move");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 110, 0x000000, "Arrow Keys - Rotate");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 140, 0x000000, "+ / - - Zoom");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 170, 0x000000, "ESC - Exit");
}
