/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:49:00 by gansari           #+#    #+#             */
/*   Updated: 2025/08/21 15:09:25 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player_input(t_game *game)
{
	game->player.key_w = 0;
	game->player.key_s = 0;
	game->player.key_a = 0;
	game->player.key_d = 0;
	game->player.key_left = 0;
	game->player.key_right = 0;
}

void	handle_game_error(t_game *game, char *error_message)
{
	printf("%s", error_message);
	free_texture_paths(game);
	free_string_array(game->map.grid);
	destroy_mlx_images(game);
	if (game->mlx.window && game->mlx.instance)
		mlx_destroy_window(game->mlx.instance, game->mlx.window);
	if (game->mlx.instance)
	{
		mlx_destroy_display(game->mlx.instance);
		free(game->mlx.instance);
	}
	exit(EXIT_FAILURE);
}

void	init_game_settings(t_game *game)
{
	game->player.move_speed = MOVE_SPEED;
	game->player.rotate_speed = ROTATION_SPEED;
	game->mlx.width = DEFAULT_WIDTH;
	game->mlx.height = DEFAULT_HEIGHT;
	if (game->player.initial_dir == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.initial_dir == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.initial_dir == 'W')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (game->player.initial_dir == 'E')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
}

void	load_texture_image(t_game *game, t_image *texture)
{
	if (!texture->path)
		return ;
	texture->mlx_ptr = mlx_xpm_file_to_image(game->mlx.instance, 
			texture->path, &texture->width, &texture->height);
	if (!texture->mlx_ptr)
		handle_game_error(game, "Error\nFailed to load texture file\n");
	texture->data = mlx_get_data_addr(texture->mlx_ptr,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->data)
		handle_game_error(game, "Error\nFailed to get texture data address\n");
}

void	init_mlx_images(t_game *game)
{
	load_texture_image(game, &game->textures.north);
	load_texture_image(game, &game->textures.south);
	load_texture_image(game, &game->textures.east);
	load_texture_image(game, &game->textures.west);
	game->textures.screen.mlx_ptr = mlx_new_image(game->mlx.instance,
			game->mlx.width, game->mlx.height);
	if (!game->textures.screen.mlx_ptr)
		handle_game_error(game, "Error\nFailed to create display buffer\n");
	game->textures.screen.data = mlx_get_data_addr(
			game->textures.screen.mlx_ptr,
			&game->textures.screen.bits_per_pixel,
			&game->textures.screen.line_length,
			&game->textures.screen.endian);
	if (!game->textures.screen.data)
		handle_game_error(game, ERR_SCREEN_BUFFER);
}
