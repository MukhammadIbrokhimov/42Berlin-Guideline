/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:59:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/29 13:52:35 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

//void ft_close(fdf *data)
//{
//	if (data->mlx)
//	{
//		if (data->img)
//			mlx_destroy_image(data->mlx, data->img);
//		if (data->wnd)
//			mlx_destroy_window(data->mlx, data->wnd);
//		if (data->mlx)
//			mlx_destroy_display(data->mlx);
//		free(data->mlx);
//	}
//	free_map(data->map.render_map);
//	free(data);
//}

void ft_close(fdf *data)
{
	if (data)
	{
		if (data->mlx)
		{
			if (data->wnd)
			{
				mlx_destroy_window(data->mlx, data->wnd);
				data->wnd = NULL;
			}
			if (data->mlx)
			{
				mlx_destroy_display(data->mlx);
				data->mlx = NULL;
			}
			free(data->mlx);
			data->mlx = NULL;
		}
		if (data->map.render_map)
		{
			free_map(data->map.render_map);
			data->map.render_map = NULL;
		}
		free(data);
		data = NULL;
	}
}

fdf	*ft_lst(void)
{
	fdf	*data;

	data = NULL;
	data = (fdf *) malloc(sizeof(fdf));
	if (!data)
		return (NULL);
	data->side.iso = 0;
	data->color = 0xffff;
	data->window.depth = 2;
	data->window.offset_x = (WIN_WIDTH / 3) + (WIN_WIDTH / 10);
	data->window.offset_y = (WIN_HEIGHT / 10);
	data->window.zoom = 0;
	data->window.shift_down = 0;
	data->window.shift_up = 0;
	data->window.shift_left = -80;
	data->window.shift_right = -80;
	data->mlx = NULL;
	data->wnd = NULL;
	data->img = NULL;
	return (data);
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_map(int **arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

//void ft_print(int **map, int height, int width)
//{
//	int i, j;

//	i = 0;
//	if (!map)
//		return;

//	for (int i = 0; i < height; i++) {
//		for (int j = 0; j < width; j++) {
//			printf("%3d", map[i][j]);
//		}
//		printf("\n");
//	}

//}
