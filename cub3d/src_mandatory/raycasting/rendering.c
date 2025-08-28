/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:51:56 by gansari           #+#    #+#             */
/*   Updated: 2025/08/22 15:47:05 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

int	render_frame(t_game *game)
{
	process_movement_input(game);
	render_background_colors(game);
	execute_raycasting(game);
	mlx_put_image_to_window(game->mlx.instance, game->mlx.window,
		game->textures.screen.mlx_ptr, 0, 0);
	return (0);
}
