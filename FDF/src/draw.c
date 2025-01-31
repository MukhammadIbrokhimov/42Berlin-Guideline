/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:00:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 19:29:02 by mukibrok         ###   ########.fr       */
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
	int	auto_scale;
	int	max_x = data->map.width;
	int	max_y = data->map.height;
	int max_dimension = (max_x > max_y) ? max_x : max_y;
	float scale_factor_x = (WIN_WIDTH * 0.8) / max_dimension;
	float scale_factor_y = (WIN_HEIGHT * 0.8) / max_dimension;

	auto_scale = (scale_factor_x < scale_factor_y) ? scale_factor_x : scale_factor_y;
	if (auto_scale > 10)
		auto_scale = 10;
	p->x1 *= auto_scale + data->window.zoom;
	p->y1 *= auto_scale + data->window.zoom;
	p->x2 *= auto_scale + data->window.zoom;
	p->y2 *= auto_scale + data->window.zoom;
	data->side.z1 *= auto_scale + data->window.zoom + data->side.iso;
	data->side.z2 *= auto_scale + data->window.zoom + data->side.iso;
}

void	locate(t_point *p, fdf *data)
{
	p->x1 += (WIN_WIDTH / 2) - (data->map.width * data->window.zoom / 2) + data->window.shift_left;
	p->y1 += (WIN_HEIGHT / 8) - (data->map.height * data->window.zoom / 2) + data->window.shift_up;
	p->x2 += (WIN_WIDTH / 2) - (data->map.width * data->window.zoom / 2) + data->window.shift_right;
	p->y2 += (WIN_HEIGHT / 8) - (data->map.height * data->window.zoom / 2) + data->window.shift_down;
}
