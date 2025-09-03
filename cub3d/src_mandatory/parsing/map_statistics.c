/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_statistics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:48:57 by mukibrok          #+#    #+#             */
/*   Updated: 2025/09/02 15:39:38 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

/**
 * @brief Set player position and initial direction vectors
 */

void	set_player_position(t_game *game, char direction,
		int row, int col)
{
	game->player.pos_y = (double)row + 0.5;
	game->player.pos_x = (double)col + 0.5;
	game->player.initial_dir = direction;
	if (direction == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	else if (direction == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
	}
}

int	scan_row(char *row, t_scan_data *data)
{
	int	c;

	c = 0;
	while (row[c])
	{
		if (is_character_valid(row[c], "NSEW"))
		{
			set_player_position(data->game, row[c],
				data->row, data->base + c);
			(*data->player_count)++;
		}
		if (!is_character_valid(row[c], "10 \nNSEW"))
			(*data->player_count)++;
		c++;
	}
	return (c);
}

static void	set_map_dimensions(t_game *game, int pc, int max_w, int row)
{
	if (pc == 1)
	{
		game->map.width = max_w;
		game->map.height = row;
	}
	else
	{
		game->map.width = 0;
		game->map.height = 0;
	}
}

void	calculate_map_dimensions(t_game *game, char **map, int srow, int scol)
{
	int			row;
	int			max_w;
	int			pc;
	int			w;
	t_scan_data	data;

	row = srow;
	max_w = 0;
	pc = 0;
	data.game = game;
	data.player_count = &pc;
	while (map[row])
	{
		data.row = row;
		data.base = scol;
		w = scan_row(map[row] + scol, &data);
		if (w > max_w)
			max_w = w;
		row++;
	}
	set_map_dimensions(game, pc, max_w, row);
}

/**
 * @brief Validate that all required configuration elements are present
 */

void	validate_configuration_completeness(t_game *game)
{
	int	color_index;

	if (!game->textures.north.path || !game->textures.south.path
		|| !game->textures.west.path || !game->textures.east.path)
	{
		handle_parsing_error(game, ERR_MISSING_TEXTURE);
	}
	color_index = 0;
	while (color_index < 3)
	{
		if (game->map.floor_rgb[color_index] == -1
			|| game->map.ceiling_rgb[color_index] == -1)
		{
			handle_parsing_error(game, ERR_INVALID_COLOR);
		}
		color_index++;
	}
}
