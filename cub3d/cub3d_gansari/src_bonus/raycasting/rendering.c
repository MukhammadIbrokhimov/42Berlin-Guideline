/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:51:56 by gansari           #+#    #+#             */
/*   Updated: 2025/08/29 18:43:04 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

int	render_frame(t_game *game)
{
	process_movement_input(game);
	render_background_colors(game);
	execute_raycasting(game);
	draw_minimap_display(game);
	draw_player_direction_line(game);
	draw_minimap_case(game, (int)game->player.pos_x * MINIMAP_SCALE,
		(int)game->player.pos_y * MINIMAP_SCALE, COLOR_PLAYER);
	mlx_put_image_to_window(game->mlx.instance, game->mlx.window,
		game->textures.screen.mlx_ptr, 0, 0);
	mlx_put_image_to_window(game->mlx.instance, game->mlx.window,
		game->textures.minimap.mlx_ptr, MINIMAP_OFFSET, MINIMAP_OFFSET);
	return (0);
}
