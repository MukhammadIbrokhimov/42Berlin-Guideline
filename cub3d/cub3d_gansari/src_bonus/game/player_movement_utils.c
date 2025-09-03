/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:40:15 by gansari           #+#    #+#             */
/*   Updated: 2025/09/01 12:10:43 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

static void	handle_diagonal_collision(t_game *game, double new_x, double new_y)
{
	int	x_blocked;
	int	y_blocked;

	x_blocked = is_wall_at_position(game, (int)new_x,
			(int)game->player.pos_y);
	y_blocked = is_wall_at_position(game, (int)game->player.pos_x,
			(int)new_y);
	if (x_blocked && y_blocked)
		return ;
	if (!x_blocked && y_blocked)
		game->player.pos_x = new_x;
	else if (x_blocked && !y_blocked)
		game->player.pos_y = new_y;
}

static void	handle_free_diagonal(t_game *game, double new_x, double new_y)
{
	int	x_blocked;
	int	y_blocked;

	x_blocked = is_wall_at_position(game, (int)new_x,
			(int)game->player.pos_y);
	y_blocked = is_wall_at_position(game, (int)game->player.pos_x,
			(int)new_y);
	if (!x_blocked)
		game->player.pos_x = new_x;
	if (!y_blocked)
		game->player.pos_y = new_y;
}

void	handle_diagonal_movement(t_game *game, double new_x, double new_y)
{
	int	diagonal_blocked;

	diagonal_blocked = is_wall_at_position(game, (int)new_x, (int)new_y);
	if (diagonal_blocked)
		handle_diagonal_collision(game, new_x, new_y);
	else
		handle_free_diagonal(game, new_x, new_y);
}

void	handle_single_axis_movement(t_game *game, double delta_x,
							double delta_y)
{
	double	new_x;
	double	new_y;
	int		x_blocked;
	int		y_blocked;

	new_x = game->player.pos_x + delta_x;
	new_y = game->player.pos_y + delta_y;
	x_blocked = is_wall_at_position(game, (int)new_x,
			(int)game->player.pos_y);
	y_blocked = is_wall_at_position(game, (int)game->player.pos_x,
			(int)new_y);
	if (!x_blocked && delta_x != 0.0)
		game->player.pos_x = new_x;
	if (!y_blocked && delta_y != 0.0)
		game->player.pos_y = new_y;
}

void	revert_invalid_position(t_game *game, double delta_x, double delta_y)
{
	if (is_wall_at_position(game, (int)game->player.pos_x,
			(int)game->player.pos_y))
	{
		game->player.pos_x -= delta_x;
		game->player.pos_y -= delta_y;
	}
}
