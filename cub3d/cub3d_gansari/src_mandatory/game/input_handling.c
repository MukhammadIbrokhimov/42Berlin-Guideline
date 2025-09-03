/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:50:44 by gansari           #+#    #+#             */
/*   Updated: 2025/08/29 18:51:43 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		clean_exit_program(game);
	else if (keycode == KEY_W)
		game->player.key_w = 1;
	else if (keycode == KEY_S)
		game->player.key_s = 1;
	else if (keycode == KEY_A)
		game->player.key_a = 1;
	else if (keycode == KEY_D)
		game->player.key_d = 1;
	else if (keycode == KEY_LEFT)
		game->player.key_left = 1;
	else if (keycode == KEY_RIGHT)
		game->player.key_right = 1;
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.key_w = 0;
	else if (keycode == KEY_S)
		game->player.key_s = 0;
	else if (keycode == KEY_A)
		game->player.key_a = 0;
	else if (keycode == KEY_D)
		game->player.key_d = 0;
	else if (keycode == KEY_LEFT)
		game->player.key_left = 0;
	else if (keycode == KEY_RIGHT)
		game->player.key_right = 0;
	return (0);
}

static void	process_player_key_input(t_game *game,
	double *move_x, double *move_y)
{
	if (game->player.key_w)
	{
		*move_x += game->player.dir_x * game->player.move_speed;
		*move_y += game->player.dir_y * game->player.move_speed;
	}
	if (game->player.key_s)
	{
		*move_x -= game->player.dir_x * game->player.move_speed;
		*move_y -= game->player.dir_y * game->player.move_speed;
	}
	if (game->player.key_a)
	{
		*move_x -= game->player.plane_x * game->player.move_speed;
		*move_y -= game->player.plane_y * game->player.move_speed;
	}
	if (game->player.key_d)
	{
		*move_x += game->player.plane_x * game->player.move_speed;
		*move_y += game->player.plane_y * game->player.move_speed;
	}
}

void	process_movement_input(t_game *game)
{
	double	move_x;
	double	move_y;

	move_x = 0.0;
	move_y = 0.0;
	process_player_key_input(game, &move_x, &move_y);
	if (move_x != 0.0 || move_y != 0.0)
		move_player_with_collision(game, move_x, move_y);
	if (game->player.key_left)
	{
		if (game->player.initial_dir == 'N' || game->player.initial_dir == 'S')
			rotate_player_view(game, -game->player.rotate_speed);
		else
			rotate_player_view(game, game->player.rotate_speed);
	}
	if (game->player.key_right)
	{
		if (game->player.initial_dir == 'N' || game->player.initial_dir == 'S')
			rotate_player_view(game, game->player.rotate_speed);
		else
			rotate_player_view(game, -game->player.rotate_speed);
	}
}
