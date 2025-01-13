/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:56:23 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/13 18:13:27 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void draw_map(fdf *map)
{
	int	y;
	int	x;

	if (!map || !map->render_map)
		return;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				wu_line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				wu_line(x, y, x, y + 1, map);
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
	//map->zoom = 20;
	x1 *= map->zoom, y1 *= map->zoom, x2 *= map->zoom, y2 *= map->zoom;
	dy = y2 - y1;
	dx = x2 - x1;
	project_isometric(&x1, &y1, &z, map);
	project_isometric(&x2, &y2, &z1, map);
	x1 += 250;
	y1 += 150;
	x2 += 250;
	y2 += 150;
	slope = dy / dx;
	steep = (fabs((double)slope) > 1.0);  // Check if the line is steep
	if (steep)
	{
		ft_swap(&x1, &y1);
		ft_swap(&x2, &y2);
	}
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	float error = 3.5;
	while ((int) (x1 - x2)) {
		float brightness = 1.3 - error; // Adjust brightness based on how far the pixel is from the ideal line
		//int color = (z || z1) ? COLOR_BRICK_RED : TEXT_COLOR;
		//int r = (color >> 16) & 0xFF;
		//int g = (color >> 8) & 0xFF;
		//int b = color & 0xFF;
		//r = (int)(r * brightness);
		//g = (int)(g * brightness);
		//b = (int)(b * brightness);
		//int adjusted_color = (r << 16) | (g << 8) | b;
		if (steep)
			plot_pixel(map, y1, x1, brightness);
			//mlx_pixel_put(map->mlx, map->wnd, y1, x1, adjusted_color);
		else
			plot_pixel(map, x1, y1, brightness);
			//mlx_pixel_put(map->mlx, map->wnd, x1, y1, adjusted_color);
		error += dy / dx;
		if (error >= 1) {
			y1++;
			error -= 1;
		}
		x1++;
	}
}

//void wu_line(fdf *map, float x1, float y1, float x2, float y2)
//{
//	float	steep;
//	float	gradient;
//	float	dx;
//	float	dy;

//	x1 *= map->zoom;
//	x2 *= map->zoom;
//	y1 *= map->zoom;
//	y2 *= map->zoom;
//	steep = abs(y2 - y1) > abs(x2 - x1);
//	dx = x2 - x1;
//	dy = y2 - y1;
//	if (steep)
//	{
//		ft_swap(&x1, &y1);
//		ft_swap(&x2, &y2);
//	}
//	if (x1 > x2)
//	{
//		ft_swap(&x1, &x2);
//		ft_swap(&y1, &y2);
//	}
//	gradient = (dx == 0) ? 1 : dy / dx;
//	int x_end = roundf(x1);
//	float y_end = y1 + gradient * (x_end - x1);
//	float x_gap = reverse_fractional_part(x1 + 0.5);
//	int x_pixel1 = x_end;
//	int y_pixel1 = floorf(y_end);
//	if (steep) {
//		plot_pixel(map, y_pixel1, x_pixel1, reverse_fractional_part(y_end) * x_gap);
//		plot_pixel(map, y_pixel1 + 1, x_pixel1, fractional_part(y_end) * x_gap);
//	} else {
//		plot_pixel(map, x_pixel1, y_pixel1, reverse_fractional_part(y_end) * x_gap);
//		plot_pixel(map, x_pixel1, y_pixel1 + 1, fractional_part(y_end) * x_gap);
//	}
//	float inter_y = y_end + gradient;

//	// Handle the second endpoint
//	x_end = roundf(x1);
//	y_end = y1 + gradient * (x_end - x1);
//	x_gap = fractional_part(x1 + 0.5);
//	int x_pixel2 = x_end;
//	int y_pixel2 = floorf(y_end);
//	if (steep) {
//	plot_pixel(map, y_pixel2, x_pixel2, reverse_fractional_part(y_end) * x_gap);
//	plot_pixel(map, y_pixel2 + 1, x_pixel2, fractional_part(y_end) * x_gap);
//	} else {
//	plot_pixel(map, x_pixel2, y_pixel2, reverse_fractional_part(y_end) * x_gap);
//	plot_pixel(map, x_pixel2, y_pixel2 + 1, fractional_part(y_end) * x_gap);
//	}

//	int	x = x_pixel1 + 1;
//	while (x <= x_pixel2)
//	{
//		int	y = floorf(inter_y);
//	if (steep) {
//		plot_pixel(map, y, x, reverse_fractional_part(inter_y));
//		plot_pixel(map, y + 1, x, fractional_part(inter_y));
//	} else {
//		plot_pixel(map, x, y, reverse_fractional_part(inter_y));
//		plot_pixel(map, x, y + 1, fractional_part(inter_y));
//	}
//	inter_y += gradient;
//	}
//}


void ft_swap(float *a, float *b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}


void project_isometric(float *x, float *y, int *z, fdf *map)
{
	int previous_x = *x;
	int previous_y = *y;

	float angle = M_PI / 4; // 30 degrees
	*x = (previous_x - previous_y) * cos(0.8);
	*y = (previous_x + previous_y) * sin(0.8) - *z;
}

float fractional_part(float x)
{
	return x - floorf(x);
}

// Helper function to calculate 1 - fractional part
float reverse_fractional_part(float x) {
	return (0.5 - fractional_part(x));
}

// Function to plot a pixel with intensity
void plot_pixel(fdf *data, int x, int y, float intensity)
{
	int color = (int)(255 * intensity); // Convert intensity to grayscale
	int rgb = (color << 16) | (color << 8) | color; // Pack RGB values
	mlx_pixel_put(data->mlx, data->wnd, x, y, rgb);
}
