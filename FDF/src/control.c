/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/16 15:48:11 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	do_commands(int	command, fdf *map)
{
	ft_printf("Pressed: %d\n width: %d\n", command, map->width);
	if (command == 65307)
	{
		ft_printf("Escape key was pressed\n");
		ft_close(map);
		exit(0);
	}
	else if (command == 65362 || command == 65364)
		up_or_down(map, command);
	else if (command == 65361 || command == 65363)
		left_or_right(map, command);
	else
		ft_printf("Pressed: %d\n width: %d\n", command, map->width);
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
	mlx_clear_window(map->mlx, map->wnd);
	//draw_map(map);
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
	mlx_clear_window(map->mlx, map->wnd);
	//draw_map(map);
}