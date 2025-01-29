/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/29 13:50:35 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int handle_keypress(int key, fdf *data)
{
	data->window.key_states[key] = 1;

	if (key == ESC)
	{
		ft_printf("Escape key pressed\n");
		ft_close(data);
		exit(0);
	}
	return (0);
}

int	handle_close(int keycode, fdf *data)
{
	(void)keycode;
	ft_printf("Window close event triggered\n");
	ft_close(data);
	exit(0);
	return (0);
}

int handle_keyrelease(int key, fdf *data)
{
	data->window.key_states[key] = 0;
	return (0);
}


void update_keys(fdf *data)
{
	if (data->window.key_states[65362])
		up_or_down(data, 65362);
	if (data->window.key_states[65364])
		up_or_down(data, 65364);
	if (data->window.key_states[65361])
		left_or_right(data, 65361);
	if (data->window.key_states[65363])
		left_or_right(data, 65363);
	if (data->window.key_states[NUMPAD_8] || data->window.key_states[NUMPAD_2]) // Isometric
		add_isometric(data, (data->window.key_states[NUMPAD_8]) ? NUMPAD_8 : NUMPAD_2);
	if ((data->window.key_states[KEY_PLUS] || data->window.key_states[NUMPAD_PLUS]) ||
			(data->window.key_states[KEY_MINUS] || data->window.key_states[NUMPAD_MINUS]))
		zoom_in_out(data);
	set_pixels(data);
}

void	zoom_in_out(fdf *data)
{
	if (data->window.key_states[KEY_PLUS] || data->window.key_states[NUMPAD_PLUS])
	{
		data->window.zoom += 1;
		set_pixels(data);
	}
	else if (data->window.key_states[KEY_MINUS] || data->window.key_states[NUMPAD_MINUS])
	{
		data->window.zoom -= 1;
		set_pixels(data);
	}
}

void	add_isometric(fdf *data, int command)
{
	if (command == NUMPAD_8)
	{
		data->side.iso += 1;
	}
	else
	{
		data->side.iso -= 1;
	}
	set_pixels(data);
}

void	up_or_down(fdf *map, int command)
{
	if (command == 65362)
	{
		map->window.shift_up -= 20;
		map->window.shift_down -= 20;
	}
	else
	{
		map->window.shift_up += 20;
		map->window.shift_down += 20;
	}
	set_pixels(map);
}

void	left_or_right(fdf *map, int command)
{
	if (command == 65361)
	{
		map->window.shift_left -= 20;
		map->window.shift_right -= 20;
	}
	else
	{
		map->window.shift_right += 20;
		map->window.shift_left += 20;
	}
	set_pixels(map);
}