/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:56:23 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/08 18:57:05 by mukibrok         ###   ########.fr       */
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
				wu_line(x * z, y * z, (x + 1) * z, y * z, map);
			if (y < map->height - 1)
				wu_line(x * z, y * z, x * z, (y + 1) * z, map);
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
		// Color the pixel at (x1, y1)
		float brightness = 1.0 - error; // The intensity, closer to 0 means less bright
		if (steep)
			mlx_pixel_put(map->mlx, map->wnd, y1, x1, (int)(brightness * 255) << 16);  // Set the pixel color (red scale)
		else
			mlx_pixel_put(map->mlx, map->wnd, x1, y1, (int)(brightness * 255) << 16);  // Set the pixel color (red scale)
		error += dy / dx;
		if (error >= 1) {
			y1++;
			error -= 1;
		}
		x1++;
	}
}