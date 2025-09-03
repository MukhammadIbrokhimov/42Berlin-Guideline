/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_coordinate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:42:06 by gansari           #+#    #+#             */
/*   Updated: 2025/09/01 17:49:42 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

static void	calculate_hit_position(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->wall.hit_x = game->player.pos_y
			+ game->ray.perp_wall_dist * game->ray.dir_y;
	}
	else
	{
		game->wall.hit_x = game->player.pos_x
			+ game->ray.perp_wall_dist * game->ray.dir_x;
	}
	game->wall.hit_x -= floor(game->wall.hit_x);
	game->wall.tex_x = (int)(game->wall.hit_x * TEXTURE_SIZE);
}

static void	adjust_texture_x_ns_direction(t_game *game)
{
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		game->wall.tex_x = TEXTURE_SIZE - game->wall.tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		game->wall.tex_x = TEXTURE_SIZE - game->wall.tex_x - 1;
}

static void	adjust_texture_x_ew_direction(t_game *game)
{
	if (game->ray.side == 0 && game->ray.dir_x < 0)
		game->wall.tex_x = TEXTURE_SIZE - game->wall.tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y > 0)
		game->wall.tex_x = TEXTURE_SIZE - game->wall.tex_x - 1;
}

static void	adjust_texture_x_coordinate(t_game *game)
{
	if (game->player.initial_dir == 'N' || game->player.initial_dir == 'S')
		adjust_texture_x_ns_direction(game);
	else
		adjust_texture_x_ew_direction(game);
}

void	calculate_texture_coordinates(t_game *game, int line_start,
		int line_height)
{
	calculate_hit_position(game);
	adjust_texture_x_coordinate(game);
	game->wall.tex_step = 1.0 * TEXTURE_SIZE / line_height;
	game->wall.tex_pos = (line_start - game->mlx.height / 2
			+ line_height / 2) * game->wall.tex_step;
}
