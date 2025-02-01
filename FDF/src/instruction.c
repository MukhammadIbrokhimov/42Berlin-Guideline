/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:24:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 20:07:58 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	put_pixel_to_img(fdf *data, int x, int y, int color)
{
	char	*dst;
	int		result;

	result = y * data->size_line + x * (data->b_per_pixel / 8);
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->address_data + result;
		*(unsigned int *)dst = color;
	}
}

// Function to draw the usage panel in the image
void	draw_usage(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = WIN_WIDTH - USAGE_WIDTH;
		while (x < WIN_WIDTH)
		{
			put_pixel_to_img(data, x, y, data->bvg_color);
			x++;
		}
		y++;
	}
}

void	display_usage_text(fdf *data)
{
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 380, 50,
		TEXT_COLOR, "Usage:");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 380, 80,
		TEXT_COLOR, "Move: Arrow Keys | WASD");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 380, 110,
		TEXT_COLOR, "Zoom: Scroll Mouse | + | -");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 380, 140,
		TEXT_COLOR, "Change Usage Color: 4 | 6");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 380, 170,
		TEXT_COLOR, "Play with 3D: 8 | 2");
	mlx_string_put(data->mlx, data->wnd, WIN_WIDTH - 380, 200,
		TEXT_COLOR, "Exit: ESC");
}

void	render_frame(fdf *data)
{
	draw_usage(data);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
	display_usage_text(data);
}
