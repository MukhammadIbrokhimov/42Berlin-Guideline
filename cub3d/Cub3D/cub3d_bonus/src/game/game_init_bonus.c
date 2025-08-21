/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:47:34 by gansari           #+#    #+#             */
/*   Updated: 2025/08/21 17:34:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_minimap_system(t_game *game)
{
	int	minimap_width;
	int	minimap_height;

	minimap_width = game->map.width * MINIMAP_SCALE;
	minimap_height = game->map.height * MINIMAP_SCALE;
	game->textures.minimap.mlx_ptr = mlx_new_image(game->mlx.instance,
			minimap_width, minimap_height);
	if (!game->textures.minimap.mlx_ptr)
		handle_game_error(game, "Error\nFailed to create minimap\n");
	game->textures.minimap.data = mlx_get_data_addr(
			game->textures.minimap.mlx_ptr,
			&game->textures.minimap.bits_per_pixel,
			&game->textures.minimap.line_length,
			&game->textures.minimap.endian);
	if (!game->textures.minimap.data)
		handle_game_error(game, "Error\nFailed to initialize minimap data\n");
	draw_minimap_display(game);
}
