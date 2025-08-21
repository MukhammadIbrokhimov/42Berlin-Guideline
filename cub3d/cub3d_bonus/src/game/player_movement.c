/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:51:12 by gansari           #+#    #+#             */
/*   Updated: 2025/08/21 17:35:49 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_with_collision(t_game *game, double delta_x, double delta_y)
{
	int		previous_grid_x;
	int		previous_grid_y;
	double	new_x;
	double	new_y;

	previous_grid_x = (int)game->player.pos_x;
	previous_grid_y = (int)game->player.pos_y;
	new_x = game->player.pos_x + delta_x;
	if (game->map.grid[(int)game->player.pos_y][(int)new_x] != '1')
		game->player.pos_x = new_x;
	new_y = game->player.pos_y + delta_y;
	if (game->map.grid[(int)new_y][(int)game->player.pos_x] != '1')
		game->player.pos_y = new_y;
	if ((int)game->player.pos_x != previous_grid_x || 
		(int)game->player.pos_y != previous_grid_y)
	{
		upd_minimap_player_pst(game, previous_grid_x, previous_grid_y);
	}
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
	game->player.dir_x = game->player.dir_x * cos_rotation - 
		game->player.dir_y * sin_rotation;
	game->player.dir_y = temp_dir_x * sin_rotation + 
		game->player.dir_y * cos_rotation;
	temp_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos_rotation - 
		game->player.plane_y * sin_rotation;
	game->player.plane_y = temp_plane_x * sin_rotation + 
		game->player.plane_y * cos_rotation;
}

int	init_game_engine(t_game *game)
{
	init_game_settings(game);
	game->mlx.instance = mlx_init();
	if (!game->mlx.instance)
		handle_game_error(game, "Error\nFailed to initialize MLX\n");
	game->mlx.window = mlx_new_window(game->mlx.instance, 
			game->mlx.width, game->mlx.height, "cub3D");
	if (!game->mlx.window)
		handle_game_error(game, "Error\nFailed to create game window\n");
	init_mlx_images(game);
	init_player_input(game);
	init_minimap_system(game);
	mlx_loop_hook(game->mlx.instance, &render_frame, game);
	mlx_hook(game->mlx.window, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->mlx.window, 3, 1L << 1, handle_key_release, game);
	mlx_hook(game->mlx.window, 17, 1L << 0, clean_exit_program, game);
	mlx_hook(game->mlx.window, 6, 1L << 6, handle_mouse_rotation, game);
	mlx_loop(game->mlx.instance);
	return (0);
}

int	handle_mouse_rotation(int mouse_x, int mouse_y, t_game *game)
{
	double	mouse_rotation_speed;

	(void) mouse_y;
	mouse_rotation_speed = game->player.rotate_speed / 3.0;
	if (game->player.initial_dir == 'N' || game->player.initial_dir == 'S')
	{
		if (mouse_x > (int)(game->mlx.width / 1.2))
			rotate_player_view(game, mouse_rotation_speed);
		else if (mouse_x < game->mlx.width / 6)
			rotate_player_view(game, -mouse_rotation_speed);
	}
	else
	{
		if (mouse_x > (int)(game->mlx.width / 1.2))
			rotate_player_view(game, -mouse_rotation_speed);
		else if (mouse_x < game->mlx.width / 6)
			rotate_player_view(game, mouse_rotation_speed);
	}
	return (0);
}