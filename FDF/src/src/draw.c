/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:00:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 19:51:15 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_pixels(fdf *data)
{
	ft_bzero(data->address_data, WIN_WIDTH * WIN_HEIGHT * 4);
	mlx_clear_window(data->mlx, data->wnd);
	draw_map(data);
	render_frame(data);
}

void	draw_map(fdf *data)
{
	t_point	p;

	if (!data || !data->map.render_map)
		return ;
	p.x1 = 0;
	while (p.x1 < data->map.width)
	{
		p.y1 = 0;
		while (p.y1 < data->map.height)
		{
			if (p.x1 < data->map.width - 1)
				line(p.x1 + 1, p.y1, data, p);
			if (p.y1 < data->map.height - 1)
				line(p.x1, p.y1 + 1, data, p);
			p.y1 += 1;
		}
		p.x1 += 1;
	}
}

void	line(int x2, int y2, fdf *data, t_point p)
{
	p.x2 = x2;
	p.y2 = y2;
	data->side.z1 = data->map.render_map[p.y1][p.x1];
	data->side.z2 = data->map.render_map[p.y2][p.x2];
	reproduce_pixels(&p, data);
	locate(&p, data);
	isometric(&p.x1, &p.y1, data->side.z1);
	isometric(&p.x2, &p.y2, data->side.z2);
	if ((p.x1 < 0 && p.x2 < 0) || (p.x1 > WIN_WIDTH && p.x2 > WIN_WIDTH)
		|| (p.y1 < 0 && p.y2 < 0) || (p.y1 > WIN_HEIGHT && p.y2 > WIN_HEIGHT))
		return ;
	data->side.dx = p.x2 - p.x1;
	data->side.dy = p.y2 - p.y1;
	if (abs(data->side.dx) > abs(data->side.dy))
		negative_slope(p.x1, p.y1, data);
	else 
		positive_slope(p.x1, p.y1, data);
}

void	reproduce_pixels(t_point *p, fdf *data)
{
	custom		math;

	if (data->map.width > data->map.height)
		math.max_d = data->map.width;
	else
		math.max_d = data->map.height;
	math.x_scale = (WIN_WIDTH * 0.8) / math.max_d;
	math.y_scale = (WIN_HEIGHT * 0.8) / math.max_d;
	if (math.x_scale < math.y_scale)
		math.scale = math.x_scale;
	else
		math.scale = math.y_scale;
	if (math.scale > 10)
		math.scale = 10;
	p->x1 *= math.scale + data->window.zoom;
	p->y1 *= math.scale + data->window.zoom;
	p->x2 *= math.scale + data->window.zoom;
	p->y2 *= math.scale + data->window.zoom;
	data->side.z1 *= math.scale + data->window.zoom + data->side.iso;
	data->side.z2 *= math.scale + data->window.zoom + data->side.iso;
}

void	locate(t_point *p, fdf *data)
{
	control	_;

	_.shift_down = data->window.shift_down;
	_.shift_up = data->window.shift_up;
	_.shift_left = data->window.shift_left;
	_.shift_right = data->window.shift_right;
	_.zoom = data->window.zoom;
	p->x1 += (WIN_WIDTH / 2) - (data->map.width * _.zoom / 2) + _.shift_left;
	p->y1 += (WIN_HEIGHT / 8) - (data->map.height * _.zoom / 2) + _.shift_up;
	p->x2 += (WIN_WIDTH / 2) - (data->map.width * _.zoom / 2) + _.shift_right;
	p->y2 += (WIN_HEIGHT / 8) - (data->map.height * _.zoom / 2) + _.shift_down;
}
