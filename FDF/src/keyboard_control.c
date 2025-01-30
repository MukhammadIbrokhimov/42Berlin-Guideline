/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/30 20:16:47 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_keypress(int key, fdf *data)
{
	data->window.key_states[key] = 1;
	if (key == ESC)
	{
		ft_printf("Escape key pressed\n");
		ft_close(data);
		exit(0);
	}
	if ((key == KEY_6 || key == NUMPAD_6)
		|| (key == KEY_4 || key == NUMPAD_4))
		change_color(key, data);
	return (0);
}

int	handle_keyrelease(int key, fdf *data)
{
	data->window.key_states[key] = 0;
	return (0);
}

void	update_keys(fdf *data)
{
	if (data->window.key_states[65362])
		up_or_down(data, 65362);
	if (data->window.key_states[65364])
		up_or_down(data, 65364);
	if (data->window.key_states[65361])
		left_or_right(data, 65361);
	if (data->window.key_states[65363])
		left_or_right(data, 65363);
	if (data->window.key_states[NUMPAD_8]
		|| data->window.key_states[NUMPAD_2])
	{
		if (data->window.key_states[NUMPAD_8])
			add_isometric(data, NUMPAD_8);
		else
			add_isometric(data, NUMPAD_2);
	}
	if ((data->window.key_states[KEY_PLUS]
			|| data->window.key_states[NUMPAD_PLUS])
		|| (data->window.key_states[KEY_MINUS]
			|| data->window.key_states[NUMPAD_MINUS]))
		zoom_in_out(data);
}
