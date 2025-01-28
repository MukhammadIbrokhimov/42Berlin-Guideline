/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:00:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 14:29:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixels(fdf *data)
{
	//mlx_clear_window(data->mlx, data->wnd);
	//set_background(data, 0x000000); // Set background to black
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}

void draw_map(fdf *data)
{
	int y;
	int x;

	if (!data || !data->map.render_map)
		return;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (x < data->map.width - 1)
				line(x, y, x + 1, y, data);
			if (y < data->map.height - 1)
				line(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}

void line(int x1, int y1, int x2, int y2, fdf *data)
{
	int	z1;
	int	z2;
	int	p;

	data->side.z1 = data->map.render_map[y1][x1];
	data->side.z2 = data->map.render_map[y2][x2];

	x1 *= 20;
	y1 *= 20;
	x2 *= 20;
	y2 *= 20;
	data->side.z1 *= 20;
	data->side.z2 *= 20;
	data->side.dx = x2 - x1;
	data->side.dy = y2 - y1;
	if (abs(data->side.dx) > abs(data->side.dy))
		negative_slope(x1, y1, data);
	else
		positive_slope(x1, y1, data);
}

void	negative_slope(int x1, int y1, fdf *data)
{
	int	i;
	int	p;

	p = (2 * abs(data->side.dy)) - abs(data->side.dx);
	i = -1;
	while (++i < abs(data->side.dx))
	{
		if (data->side.dx > 0)
			x1++;
		else
			x1--;
		if (p < 0)
			p = p + (2 * abs(data->side.dy));
		else
		{
			if (data->side.dy > 0)
				y1++;
			else
				y1--;
			p = p + (2 * abs(data->side.dy)) - (2 *abs(data->side.dx));
		}
		put_pixel_less(data, x1, y1);
	}
}

void	positive_slope(int x1, int y1, fdf *data)
{
	int	i;
	int	p;

	p = (2 * abs(data->side.dy)) - abs(data->side.dx);
	i = -1;
	while (++i < abs(data->side.dy))
	{
		if (data->side.dy > 0)
			y1++;
		else
			y1--;
		if (p < 0)
			p = p + (2 * abs(data->side.dx));
		else
		{
			if (data->side.dx > 0)
				x1++;
			else
				x1--;
			p = p + (2 * abs(data->side.dx)) - (2 *abs(data->side.dy));
		}
		put_pixel_big(data, x1, y1);
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

		// Interpolation based on X
		data->color = get_color(data->side.z1, data->side.z2); // Modify this line as needed for X-based interpolation

		addr[pixel + 0] = (data->color >> 0) & 255;  // Red
		addr[pixel + 1] = (data->color >> 8) & 255;  // Green
		addr[pixel + 2] = (data->color >> 16) & 255; // Blue
		addr[pixel + 3] = (data->color >> 24) & 255; // Alpha
	}
}

void put_pixel_big(fdf *data, int x, int y)
{
	char *addr;
	int pixel;

	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		addr = data->address_data;
		pixel = y * data->size_line + x * 4;

		// Interpolation based on Y
		data->color = get_color(data->side.z1, data->side.z2); // Modify this line as needed for Y-based interpolation

		addr[pixel + 0] = (data->color >> 0) & 255;  // Red
		addr[pixel + 1] = (data->color >> 8) & 255;  // Green
		addr[pixel + 2] = (data->color >> 16) & 255; // Blue
		addr[pixel + 3] = (data->color >> 24) & 255; // Alpha
	}
}



//void set_background(fdf *data, int color)
//{
//	int x;
//	int y;

//	y = 0;
//	while (y < data->map.height)
//	{
//		x = 0;
//		while (x < data->map.width)
//		{
//			put_pixel(data, x, y, color);
//			x++;
//		}
//		y++;
//	}
//}
