/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:37:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/15 17:15:34 by mukibrok         ###   ########.fr       */
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
	if (!map->mlx)
		return (free_map(map->render_map), free(map), 1);
	map->wnd = mlx_new_window(map->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!map->wnd)
		return (ft_close(map), 1);
	map->img = mlx_new_image(map->mlx, WIN_WIDTH, WIN_HEIGHT);
	map->address_data = mlx_get_data_addr(map->img, &map->b_per_pixel, &map->size_line, &map->endian);
	mlx_put_image_to_window(map->mlx, map->wnd, map->img, 0, 0);
	set_pixels(map);
	mlx_key_hook(map->wnd, do_commands, map);
	//mlx_mouse_hook(map->wnd, do_commands, map);
	mlx_loop(map->mlx);
	return (0);
}
