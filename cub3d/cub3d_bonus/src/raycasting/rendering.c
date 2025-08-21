/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:51:56 by gansari           #+#    #+#             */
/*   Updated: 2025/08/21 17:38:59 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_frame(t_game *game)
{
	process_movement_input(game);
	render_background_colors(game);
	execute_raycasting(game);
	mlx_put_image_to_window(game->mlx.instance, game->mlx.window, 
		game->textures.screen.mlx_ptr, 0, 0);
	mlx_put_image_to_window(game->mlx.instance, game->mlx.window,
		game->textures.minimap.mlx_ptr, MINIMAP_OFFSET, MINIMAP_OFFSET);
	return (0);
}
