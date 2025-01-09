/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:56:23 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/09 19:29:38 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void draw_map(fdf *map)
{
	int	y;
	int	x;
	int	z;

	z = map->zoom;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				wu_line(x, y, (x + 1), y, map);
			if (y < map->height - 1)
				wu_line(x, y, x, (y + 1), map);
			x++;
		}
		y++;
	}
}


void wu_line(float x1, float y1, float x2, float y2, fdf *map)
{
	float	dy;
	float	dx;
	float	slope;
	float	steep;
	int		z;
	int		z1;

	z = map->render_map[(int)y1][(int)x1];
	z1 = map->render_map[(int)y2][(int)x2];
	map->zoom = 20;
	x1 *= map->zoom, y1 *= map->zoom, x2 *= map->zoom, y2 *= map->zoom;
	dy = y2 - y1;
	dx = x2 - x1;
	slope = dy / dx;
	steep = (fabs((double)slope) > 1.0);  // Check if the line is steep
	if (steep)
	{
		float temp = x1;
		x1 = y1;
		y1 = temp;
		temp = x2;
		x2 = y2;
		y2 = temp;
	}
	// Use the already defined dx and dy variables
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	// Compute the fractional error
	float error = 0.5;

	// Draw the line
	while ((int) (x1 - x2)) {
		// Example to modify color brightness based on error
		float brightness = 1.3 - error; // Adjust brightness based on how far the pixel is from the ideal line
		int color = (z) ? COLOR_BRICK_RED : TEXT_COLOR;

		// Create a "darker" version of the color by scaling the RGB components
		int r = (color >> 16) & 0xFF; // Extract red component
		int g = (color >> 8) & 0xFF;  // Extract green component
		int b = color & 0xFF;         // Extract blue component

		// Adjust the brightness
		r = (int)(r * brightness);
		g = (int)(g * brightness);
		b = (int)(b * brightness);

		// Reassemble the color with the adjusted brightness
		int adjusted_color = (r << 16) | (g << 8) | b;

		// Then use the adjusted color to plot the pixel
		if (steep)
			mlx_pixel_put(map->mlx, map->wnd, y1, x1, adjusted_color);
		else
			mlx_pixel_put(map->mlx, map->wnd, x1, y1, adjusted_color);

		error += dy / dx;
		if (error >= 1) {
			y1++;
			error -= 1;
		}
		x1++;
	}
}