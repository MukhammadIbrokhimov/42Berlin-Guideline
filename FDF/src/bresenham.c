/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:04:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 17:13:35 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
			p = p + (2 * abs(data->side.dy)) - (2 * abs(data->side.dx));
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
			p = p + (2 * abs(data->side.dx)) - (2 * abs(data->side.dy));
		}
		put_pixel_big(data, x1, y1);
	}
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