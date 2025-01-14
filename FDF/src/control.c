/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:57:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/14 18:56:33 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	up_or_down(fdf *map, int command)
{
	if (command == 65362)
		map->shift_up -= 20;
	else
		map->shift_down += 20;
	mlx_clear_window(map->mlx, map->wnd);
	draw_map(map);
}

void	left_or_right(fdf *map, int command)
{
	if (command == 65361)
		map->shift_left -= 20;
	else
		map->shift_right += 20;
	mlx_clear_window(map->mlx, map->wnd);
	draw_map(map);
}