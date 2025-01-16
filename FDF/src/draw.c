/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:00:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/16 17:12:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixels(fdf *data)
{
	mlx_clear_window(data->mlx, data->wnd);
	set_background(data, 0x000000); // Set background to black
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}

void draw_map(fdf *map)
{
	int y;
	int x;

	if (!map || !map->render_map)
		return;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}

void line(int x1, int y1, int x2, int y2, fdf *data)
{
	draw_line(x1, y1, x2, y2, data);
}

void draw_line(int x1, int y1, int x2, int y2, fdf *data)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	int err2;
	while (1)
	{
		put_pixel(data, x1, y1, 0xFFFFFF); // White color for lines
		if (x1 == x2 && y1 == y2)
			break;
		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void put_pixel(fdf *map, int x, int y, int color)
{
	if (x >= 0 && x < map->width && y >= 0 && y < map->height)
	{
		unsigned int index = (y * map->size_line) + (x * 4);
		*(unsigned int *)(map->address_data + index) = color;
	}
}

void set_background(fdf *data, int color)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}
