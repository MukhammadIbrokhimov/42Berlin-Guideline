/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:03:01 by gansari           #+#    #+#             */
/*   Updated: 2025/08/28 13:29:46 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

void	free_texture_paths(t_game *game)
{
	if (game->textures.north.path)
	{
		free(game->textures.north.path);
		game->textures.north.path = NULL;
	}
	if (game->textures.south.path)
	{
		free(game->textures.south.path);
		game->textures.south.path = NULL;
	}
	if (game->textures.east.path)
	{
		free(game->textures.east.path);
		game->textures.east.path = NULL;
	}
	if (game->textures.west.path)
	{
		free(game->textures.west.path);
		game->textures.west.path = NULL;
	}
}

void	free_string_array(char **string_array)
{
	int	string_index;

	if (!string_array && !*string_array)
		return ;
	string_index = 0;
	while (string_array[string_index])
	{
		free(string_array[string_index]);
		string_array[string_index] = NULL;
		string_index++;
	}
	free(string_array);
}

void	free_parsing_buffers(t_game *game)
{
	if (game->map.current_line)
	{
		free(game->map.current_line);
		game->map.current_line = NULL;
	}
	if (game->map.data_buffer)
	{
		free(game->map.data_buffer);
		game->map.data_buffer = NULL;
	}
}
