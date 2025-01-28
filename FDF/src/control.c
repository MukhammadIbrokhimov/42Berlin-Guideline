/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 11:33:42 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	do_commands(int	command, fdf *data)
{
	ft_printf("Pressed: %d\n width: %d\n", command, data->map.width);
	if (command == 65307)
	{
		ft_printf("Escape key was pressed\n");
		ft_close(data);
		exit(0);
	}
	else if (command == 65362 || command == 65364)
		up_or_down(data, command);
	else if (command == 65361 || command == 65363)
		left_or_right(data, command);
	else
		ft_printf("Pressed: %d\n width: %d\n", command, data->map.width);
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