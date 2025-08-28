/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:56:19 by gansari           #+#    #+#             */
/*   Updated: 2025/08/25 11:56:28 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

void	draw_all_rays_on_minimap(t_game *game)
{
	int		screen_x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	screen_x = 0;
	while (screen_x < game->mlx.width)
	{
		camera_x = 2 * screen_x / (double)game->mlx.width - 1;
		ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
		ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
		draw_ray_on_minimap(game, ray_dir_x, ray_dir_y);
		screen_x += 10;
	}
}
