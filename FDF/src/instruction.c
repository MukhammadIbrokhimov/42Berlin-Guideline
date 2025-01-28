/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:24:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 19:27:04 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void draw_usage(fdf *data)
{
	int x = WIN_WIDTH - 40; // X-coordinate for the usage text (left margin)
	int y =  WIN_HEIGHT - 10; // Starting Y-coordinate for the usage text
	int line_spacing = 20; // Space between lines of text

	mlx_string_put(data->mlx, data->wnd, x, y, 0xFFFFFF, "FDF Usage:");
	y += line_spacing;
	mlx_string_put(data->mlx, data->wnd, x, y, 0xFFFFFF, "Zoom In/Out: +/-");
	y += line_spacing;
	mlx_string_put(data->mlx, data->wnd, x, y, 0xFFFFFF, "Move: Arrow Keys");
	y += line_spacing;
	mlx_string_put(data->mlx, data->wnd, x, y, 0xFFFFFF, "Rotate: Q/E, A/D");
	y += line_spacing;
	mlx_string_put(data->mlx, data->wnd, x, y, 0xFFFFFF, "Change Projection: P");
	y += line_spacing;
	mlx_string_put(data->mlx, data->wnd, x, y, 0xFFFFFF, "Reset: R");
}
