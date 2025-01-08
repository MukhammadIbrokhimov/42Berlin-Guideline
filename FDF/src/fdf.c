/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:37:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/08 18:57:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	do_commands(int	command, fdf *map)
{
	ft_printf("Pressed: %d\n width: %d\n", command, map->width);
	if (command == 4)
		map->zoom += 5;
	else if (command == 5)
		map->zoom -= 10;
}

int main(int argc, char **argv)
{
	fdf	*map;

	map = NULL;
	if (argc != 2)
		return (ft_printf("./fdf [map]\n"), 1);
	map = ft_lst();
	if (!map)
		return (-1);
	map = readfile(map, argv);
	map->mlx = mlx_init();
	map->wnd = mlx_new_window(map->mlx, 800, 600, "FDF");
	draw_map(map);
	mlx_key_hook(map->wnd, do_commands, map);
	mlx_mouse_hook(map->wnd, do_commands, map);
	mlx_loop(map->mlx);
	return (free_map(map->render_map), free(map), 0);
}
