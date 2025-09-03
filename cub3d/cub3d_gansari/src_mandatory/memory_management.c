/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:19:37 by gansari           #+#    #+#             */
/*   Updated: 2025/08/22 14:57:32 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_mandatory/cub3d.h"

int	clean_exit_program(t_game *game)
{
	free_texture_paths(game);
	free_string_array(game->map.grid);
	free_parsing_buffers(game);
	destroy_mlx_images(game);
	cleanup_mlx_resources(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	cleanup_parsing_error(t_game *game)
{
	free_string_array(game->map.grid);
	free_parsing_buffers(game);
	free_texture_paths(game);
}

void	cleanup_initialization_error(t_game *game)
{
	cleanup_parsing_error(game);
	destroy_mlx_images(game);
	cleanup_mlx_resources(game);
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
