/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:13:00 by gansari           #+#    #+#             */
/*   Updated: 2025/08/13 12:44:44 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_delta_distances(t_game *game)
{
	if (game->ray.dir_x == 0)
		game->ray.delta_dist_x = INT_MAX;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.dir_x);
	if (game->ray.dir_y == 0)
		game->ray.delta_dist_y = INT_MAX;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.dir_y);
}

void	calculate_step_and_side_distances(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - game->ray.map_x) 
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.pos_x) 
			* game->ray.delta_dist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - game->ray.map_y) 
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.pos_y) 
			* game->ray.delta_dist_y;
	}
}

void	execute_dda_algorithm(t_game *game)
{
	int	wall_hit;

	wall_hit = 0;
	while (wall_hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map.grid[game->ray.map_y][game->ray.map_x] == '1')
			wall_hit = 1;
	}
}

void	init_raycasting_for_column(t_game *game, int screen_x)
{
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
	game->ray.camera_x = 2 * screen_x / (double)game->mlx.width - 1;	
	game->ray.dir_x = game->player.dir_x + game->player.plane_x * game->ray.camera_x;
	game->ray.dir_y = game->player.dir_y + game->player.plane_y * game->ray.camera_x;
}

void	execute_raycasting(t_game *game)
{
	int	screen_x;

	screen_x = 0;
	while (screen_x < game->mlx.width)
	{
		init_raycasting_for_column(game, screen_x);
		calculate_delta_distances(game);
		calculate_step_and_side_distances(game);
		execute_dda_algorithm(game);
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = (game->ray.side_dist_x - game->ray.delta_dist_x);
		else
			game->ray.perp_wall_dist = (game->ray.side_dist_y - game->ray.delta_dist_y);
		draw_wall_column(game, screen_x);
		screen_x++;
	}
}
