/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:39:11 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/01 14:39:03 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom_in_out(fdf *data)
{
	if (data->window.key_states[KEY_PLUS]
		|| data->window.key_states[NUMPAD_PLUS])
	{
		if (data->window.zoom <= 50)
		{
			data->window.zoom += 1;
			set_pixels(data);
		}
		else
			ft_printf("Out of bound\n");
	}
	else if (data->window.key_states[KEY_MINUS]
		|| data->window.key_states[NUMPAD_MINUS])
	{
		if (data->window.zoom >= -5)
		{
			data->window.zoom -= 1;
			set_pixels(data);
		}
		else
			ft_printf("Out of bound\n");
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
		map->window.shift_up -= 5;
		map->window.shift_down -= 5;
	}
	else
	{
		map->window.shift_up += 5;
		map->window.shift_down += 5;
	}
	set_pixels(map);
}

void	left_or_right(fdf *map, int command)
{
	if (command == 65361)
	{
		map->window.shift_left -= 5;
		map->window.shift_right -= 5;
	}
	else
	{
		map->window.shift_right += 5;
		map->window.shift_left += 5;
	}
	set_pixels(map);
}
