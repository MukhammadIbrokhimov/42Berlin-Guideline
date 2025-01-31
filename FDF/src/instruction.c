/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:24:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 15:17:46 by mukibrok         ###   ########.fr       */
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
			put_pixel_to_img(data, x, y, data->bvg_color);
	}
}

void display_usage_text(fdf *data)
{
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 50, TEXT_COLOR, "Usage:");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 80, TEXT_COLOR, "WASD - Move");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 110, TEXT_COLOR, "Arrow Keys - Rot");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 140, TEXT_COLOR, "scrol mouse | + | - Zoom");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 180, 170, TEXT_COLOR, "ESC - Exit");
}

void render_frame(fdf *data)
{
	draw_usage(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
	display_usage_text(data);
}
