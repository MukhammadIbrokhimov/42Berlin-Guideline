/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:21:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 19:38:20 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_mouse(int button, int x, int y, fdf *data)
{
	ft_printf("Mouse button: %d at (%d, %d)\n", button, x, y);
	if (button == 1)
		ft_printf("Left mouse button clicked!\n");
	else if (button == 3)
		ft_printf("Right mouse button clicked!\n");
	else if (button == 4)
	{
		data->window.zoom--;
		set_pixels(data);
	}
	else if (button == 5)
	{
		data->window.zoom++;
		set_pixels(data);
	}
	return (0);
}
