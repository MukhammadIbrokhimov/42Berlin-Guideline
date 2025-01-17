/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:00:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/17 13:52:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixels(fdf *data)
{
	mlx_clear_window(data->mlx, data->wnd);
	//set_background(data, 0x000000); // Set background to black
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

void line(float x1, float y1, float x2, float y2, fdf *data)
{
    float dx, dy;
    int max, i;
    int z1, z2;

    z1 = data->render_map[(int)y1][(int)x1] * data->window.depth;
    z2 = data->render_map[(int)y2][(int)x2] * data->window.depth;

    x1 = (x1 * data->window.zoom) + data->window.offset_x;
    y1 = (y1 * data->window.zoom) + data->window.offset_y;
    x2 = (x2 * data->window.zoom) + data->window.offset_x;
    y2 = (y2 * data->window.zoom) + data->window.offset_y;

    dx = x2 - x1;
    dy = y2 - y1;
    max = MAX(MOD(dx), MOD(dy));

    dx /= max;
    dy /= max;

    i = 0;
    while (i <= max)
    {
        put_pixel(data, (int)x1, (int)y1, get_color(z1, z2));
        x1 += dx;
        y1 += dy;
        i++;
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
