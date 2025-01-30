/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:00:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/30 17:37:49 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void set_pixels(fdf *data)
{
	ft_bzero(data->address_data, WIN_WIDTH * WIN_HEIGHT * 4);
	mlx_clear_window(data->mlx, data->wnd);
	//draw_usage(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}


void draw_map(fdf *data)
{
	int	y;
	int	x;

	if (!data || !data->map.render_map)
		return;

	x = 0;
	while (x < data->map.width)
	{
		y = 0;
		while (y < data->map.height)
		{
			if (x < data->map.width - 1)
				line(x, y, x + 1, y, data);
			if (y < data->map.height - 1)
				line(x, y, x, y + 1, data);
			y++;
		}
		x++;
	}
}

void line(int x1, int y1, int x2, int y2, fdf *data)
{
	data->side.z1 = data->map.render_map[y1][x1];
	data->side.z2 = data->map.render_map[y2][x2];
	reproduce_pixels(&x1, &x2, &y1, &y2, data);
	locate(&x1, &x2, &y1, &y2, data);
	isometric(&x1, &y1, data->side.z1);
	isometric(&x2, &y2, data->side.z2);
	if ((x1 < 0 && x2 < 0) || (x1 > WIN_WIDTH && x2 > WIN_WIDTH) ||
	(y1 < 0 && y2 < 0) || (y1 > WIN_HEIGHT && y2 > WIN_HEIGHT))
		return;
	data->side.dx = x2 - x1;
	data->side.dy = y2 - y1;
	if (abs(data->side.dx) > abs(data->side.dy))
		negative_slope(x1, y1, data);
	else 
		positive_slope(x1, y1, data);
}

void	isometric(int *x, int *y, int z)
{
	int		tmp_x;
	int		tmp_y;
	float	angle;

	tmp_x = *x;
	tmp_y = *y;
	angle = 0.523599;
	*x = (tmp_x - tmp_y) * cos(angle);
	*y = (tmp_x + tmp_y) * sin(angle) - z;
}

void	reproduce_pixels(int *x1, int *x2, int *y1, int *y2, fdf *data)
{
	int	max_x = data->map.width;
	int	max_y = data->map.height;
	int	auto_scale;
	int max_dimension = (max_x > max_y) ? max_x : max_y;
	float scale_factor_x = (WIN_WIDTH * 0.4) / max_dimension;
	float scale_factor_y = (WIN_HEIGHT * 0.4) / max_dimension;
	auto_scale = (scale_factor_x < scale_factor_y) ? scale_factor_x : scale_factor_y;
	if (auto_scale > 10)
		auto_scale = 10;
	*x1 *= auto_scale + data->window.zoom;
	*y1 *= auto_scale + data->window.zoom;
	*x2 *= auto_scale + data->window.zoom;
	*y2 *= auto_scale + data->window.zoom;
	data->side.z1 *= auto_scale + data->window.zoom + data->side.iso;
	data->side.z2 *= auto_scale + data->window.zoom + data->side.iso;
}


void	locate(int *x1, int *x2, int *y1, int *y2, fdf *data)
{
	*x1 += (WIN_WIDTH / 2) - (data->map.width * data->window.zoom / 2) + data->window.shift_left;
	*y1 += (WIN_HEIGHT / 8) - (data->map.height * data->window.zoom / 2) + data->window.shift_up;
	*x2 += (WIN_WIDTH / 2) - (data->map.width * data->window.zoom / 2) + data->window.shift_right;
	*y2 += (WIN_HEIGHT / 8) - (data->map.height * data->window.zoom / 2) + data->window.shift_down;
}
