/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:37:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 19:52:15 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// main mlx function
int	my_mlx(fdf *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free_map(data->map.render_map), free(data), 1);
	data->wnd = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!data->wnd)
		return (ft_close(data), 1);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (ft_close(data), 1);
	data->address_data = mlx_get_data_addr(data->img, &data->b_per_pixel,
			&data->size_line, &data->endian);
	if (!data->address_data)
		return (ft_close(data), 1);
	mlx_put_image_to_window(data->mlx, data->wnd, data->img, 0, 0);
}

// keyboard and mouse handler
void	my_hook(fdf *data)
{
	mlx_hook(data->wnd, 17, 0, close_window, data);
	mlx_hook(data->wnd, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->wnd, 3, 1L << 1, handle_keyrelease, data);
	mlx_loop_hook(data->mlx, (int (*)(void *))update_keys, data);
	mlx_hook(data->wnd, 4, 1L << 2, handle_mouse_press, data);
	mlx_hook(data->wnd, 5, 1L << 3, handle_mouse_release, data);
	mlx_hook(data->wnd, 6, 1L << 6, handle_mouse_move, data);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	data = NULL;
	if (argc != 2)
		return (ft_printf("./fdf [map]\n"), 1);
	data = ft_lst();
	if (!data)
		return (1);
	data = readfile(data, argv);
	if (!data)
		return (1);
	my_mlx(data);
	set_pixels(data);
	my_hook(data);
	mlx_loop(data->mlx);
	return (0);
}
