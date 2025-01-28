/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:37:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:54 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int argc, char **argv)
{
	fdf	*data;

	data = NULL;
	if (argc != 2)
		return (ft_printf("./fdf [map]\n"), 1);
	data = ft_lst();
	if (!data)
		return (-1);
	data = readfile(data, argv);
	ft_print(data->map.render_map, data->map.height, data->map.width);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_map(data->map.render_map), free(data), 1);
	data->wnd = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!data->wnd)
		return (ft_close(data), 1);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->address_data = mlx_get_data_addr(data->img, &data->b_per_pixel, &data->size_line, &data->endian);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
	set_pixels(data);
	mlx_key_hook(data->wnd, do_commands, data);
	//mlx_mouse_hook(map->wnd, do_commands, map);
	mlx_loop(data->mlx);
	free_map(data->map.render_map);
	free(data);
	return (0);
}
