/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/30 16:28:57 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_mouse_press(int button, int x, int y, fdf *data)
{
	if (button == 1)
		data->mouse.mouse_pressed = 1;
	data->mouse.mouse_x = x;
	data->mouse.mouse_y = y;
	return (0);
}

int	handle_mouse_release(int button, int x, int y, fdf *data)
{
	if (button == 1)
		data->mouse.mouse_pressed = 0;
	if (button == 4)
	{
		if (data->window.zoom >= -20)
		{
			data->window.zoom -= 1;
			set_pixels(data);
		}
		else
			ft_printf("Out of bound\n");
	}
	if (button == 5)
	{
		if (data->window.zoom <= 50)
		{
			data->window.zoom += 1;
			set_pixels(data);
		}
		else
			ft_printf("Out of bound\n");
	}
	return (0);
}

int	handle_mouse_move(int x, int y, fdf *data)
{
	int	dx;
	int	dy;

	if (data->mouse.mouse_pressed)
	{
		dx = x - data->mouse.mouse_x;
		dy = y - data->mouse.mouse_y;
		data->window.shift_left += dx;
		data->window.shift_right += dx;
		data->window.shift_up += dy;
		data->window.shift_down += dy;
		data->mouse.mouse_x = x;
		data->mouse.mouse_y = y;
		if (dx || dy)
			set_pixels(data);
	}
	return (0);
}
