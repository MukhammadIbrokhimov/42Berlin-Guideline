/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:05:05 by gansari           #+#    #+#             */
/*   Updated: 2025/08/22 15:11:27 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

static void	handle_movement_keys(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player_with_collision(game,
			game->player.dir_x * game->player.move_speed,
			game->player.dir_y * game->player.move_speed);
	else if (keycode == KEY_S)
		move_player_with_collision(game,
			-game->player.dir_x * game->player.move_speed,
			-game->player.dir_y * game->player.move_speed);
	else if (keycode == KEY_A)
		move_player_with_collision(game,
			-game->player.plane_x * game->player.move_speed,
			-game->player.plane_y * game->player.move_speed);
	else if (keycode == KEY_D)
		move_player_with_collision(game,
			game->player.plane_x * game->player.move_speed,
			game->player.plane_y * game->player.move_speed);
}

static void	handle_rotation_keys(int keycode, t_game *game)
{
	if ((keycode == KEY_LEFT
			&& (game->player.initial_dir == 'N'
				|| game->player.initial_dir == 'S'))
		|| (keycode == KEY_RIGHT && (game->player.initial_dir == 'E'
				|| game->player.initial_dir == 'W')))
		rotate_player_view(game, -game->player.rotate_speed);
	else if ((keycode == KEY_LEFT
			&& (game->player.initial_dir == 'E'
				|| game->player.initial_dir == 'W'))
		|| (keycode == KEY_RIGHT && (game->player.initial_dir == 'N'
				|| game->player.initial_dir == 'S')))
		rotate_player_view(game, game->player.rotate_speed);
}

int	handle_keyboard_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		clean_exit_program(game);
	else if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		handle_movement_keys(keycode, game);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		handle_rotation_keys(keycode, game);
	return (0);
}
