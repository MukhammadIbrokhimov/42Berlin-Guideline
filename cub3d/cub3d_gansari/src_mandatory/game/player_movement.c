/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:51:12 by gansari           #+#    #+#             */
/*   Updated: 2025/09/01 11:51:51 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

int	is_wall_at_position(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (1);
	return (game->map.grid[y][x] == '1');
}

void	move_player_with_collision(t_game *game, double delta_x, double delta_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + delta_x;
	new_y = game->player.pos_y + delta_y;
	if (delta_x != 0.0 && delta_y != 0.0)
		handle_diagonal_movement(game, new_x, new_y);
	else
		handle_single_axis_movement(game, delta_x, delta_y);
	revert_invalid_position(game, delta_x, delta_y);
}

void	rotate_player_view(t_game *game, double rotation_speed)
{
	double	temp_dir_x;
	double	temp_plane_x;
	double	cos_rotation;
	double	sin_rotation;

	cos_rotation = cos(rotation_speed);
	sin_rotation = sin(rotation_speed);
	temp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos_rotation
		- game->player.dir_y * sin_rotation;
	game->player.dir_y = temp_dir_x * sin_rotation
		+ game->player.dir_y * cos_rotation;
	temp_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos_rotation
		- game->player.plane_y * sin_rotation;
	game->player.plane_y = temp_plane_x * sin_rotation
		+ game->player.plane_y * cos_rotation;
}
