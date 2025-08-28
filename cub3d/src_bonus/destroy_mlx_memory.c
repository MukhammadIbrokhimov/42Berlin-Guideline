/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:53:16 by gansari           #+#    #+#             */
/*   Updated: 2025/08/22 12:48:42 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

static void	destroy_single_texture(void *mlx_instance, void **texture_ptr)
{
	if (*texture_ptr)
	{
		mlx_destroy_image(mlx_instance, *texture_ptr);
		*texture_ptr = NULL;
	}
}

static void	destroy_directional_textures(t_game *game)
{
	destroy_single_texture(game->mlx.instance,
		(void **)&game->textures.north.mlx_ptr);
	destroy_single_texture(game->mlx.instance,
		(void **)&game->textures.south.mlx_ptr);
	destroy_single_texture(game->mlx.instance,
		(void **)&game->textures.east.mlx_ptr);
	destroy_single_texture(game->mlx.instance,
		(void **)&game->textures.west.mlx_ptr);
}

static void	destroy_screen_textures(t_game *game)
{
	destroy_single_texture(game->mlx.instance,
		(void **)&game->textures.screen.mlx_ptr);
	destroy_single_texture(game->mlx.instance,
		(void **)&game->textures.minimap.mlx_ptr);
}

void	destroy_mlx_images(t_game *game)
{
	if (!game->mlx.instance)
		return ;
	destroy_directional_textures(game);
	destroy_screen_textures(game);
}

void	cleanup_mlx_resources(t_game *game)
{
	if (game->mlx.window && game->mlx.instance)
	{
		mlx_destroy_window(game->mlx.instance, game->mlx.window);
		game->mlx.window = NULL;
	}
	if (game->mlx.instance)
	{
		mlx_destroy_display(game->mlx.instance);
		free(game->mlx.instance);
		game->mlx.instance = NULL;
	}
}
