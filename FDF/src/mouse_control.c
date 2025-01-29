/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/29 12:56:41 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int handle_mouse_press(int button, int x, int y, fdf *data)
{
	if (button == 1) // Left click
		data->mouse.mouse_pressed = 1;
	data->mouse.mouse_x = x;
	data->mouse.mouse_y = y;
	return (0);
}

int handle_mouse_release(int button, int x, int y, fdf *data)
{
	if (button == 1) // Left click
		data->mouse.mouse_pressed = 0;
	if (button == 4)
	{
		data->window.zoom -= 1;
		set_pixels(data);
	}
	if (button == 5)
	{
		data->window.zoom += 1;
		set_pixels(data);
	}
	return (0);
}

int handle_mouse_move(int x, int y, fdf *data)
{
	if (data->mouse.mouse_pressed) // Move only when pressed
	{
		int dx = x - data->mouse.mouse_x;
		int dy = y - data->mouse.mouse_y;

		data->window.shift_left += dx;
		data->window.shift_right += dx;
		data->window.shift_up += dy;
		data->window.shift_down += dy;

		data->mouse.mouse_x = x;
		data->mouse.mouse_y = y;

		set_pixels(data);
	}
	return (0);
}

