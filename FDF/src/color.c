/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:31:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/30 18:47:52 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_color(int command, fdf *data)
{
	static int	changer;
	int		color[6]= {
		BACKGROUND, COLOR_DISCO, COLOR_BRICK_RED, COLOR_FLAMINGO,
		COLOR_JAFFA, COLOR_SAFFRON, 
	};
	changer = 0;
	if ((command == KEY_6)
		|| (command == NUMPAD_6))
	{
		data->color = color[changer];
		changer++;
	}
	else if ((command == KEY_4)
		|| (command == NUMPAD_4))
	{
		data->color = color[changer];
		changer--;
		ft_printf("change color\n");
	}
}

unsigned int	get_color(int z1, int z2)
{
	float	blended;
	int		red;
	int		green;

	blended = (((z1 + z2) / 2.0) + 30.0) / 110.0;
	red = (int)(blended * 255);
	green = (int)((1 - blended) * 255);
	return ((red << 16) | (green << 8) | 150);
}

void	put_pixel_big(fdf *data, int x, int y)
{
	char	*addr;
	int		pixel;

	addr = NULL;
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		addr = data->address_data;
		pixel = y * data->size_line + x * 4;
		data->color = get_color(data->side.z1, data->side.z2);
		addr[pixel + 0] = (data->color >> 0) & 255;
		addr[pixel + 1] = (data->color >> 8) & 255;
		addr[pixel + 2] = (data->color >> 16) & 255;
		addr[pixel + 3] = (data->color >> 24) & 255;
	}
}

void	put_pixel_less(fdf *data, int x, int y)
{
	char	*addr;
	int		pixel;

	addr = NULL;
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		addr = data->address_data;
		pixel = y * data->size_line + x * 4;
		data->color = get_color(data->side.z1, data->side.z2);
		addr[pixel + 0] = (data->color >> 0) & 255;
		addr[pixel + 1] = (data->color >> 8) & 255;
		addr[pixel + 2] = (data->color >> 16) & 255;
		addr[pixel + 3] = (data->color >> 24) & 255;
	}
}
