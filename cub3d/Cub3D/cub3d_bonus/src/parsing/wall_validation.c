/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:02:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/21 14:02:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdbool.h>

/**
 * @brief Validate a single map row (horizontal check)
 */

bool	validate_map_row(char *row)
{
	int	i;

	if (!is_character_valid(row[0], "1 "))
		return (false);
	i = 0;
	while (row[i])
	{
		if (!is_character_valid(row[i], "10NSEW "))
			return (false);
		if (row[i] == ' ')
		{
			if (i > 0 && row[i - 1] != '1')
				return (false);
			while (row[i] == ' ')
				i++;
			if (row[i] && row[i] != '1')
				return (false);
		}
		if (row[i])
			i++;
	}
	return (is_character_valid(row[i - 1], "1 "));
}

/**
 * @brief Validate a single map column (vertical check)
 */

bool	validate_map_col(char **grid, int col, int height)
{
	int	row;

	if (!is_character_valid(grid[0][col], "1 "))
		return (false);
	row = 0;
	while (row < height)
	{
		if (!is_character_valid(grid[row][col], "10NSEW "))
			return (false);
		if (grid[row][col] == ' ')
		{
			if (row > 0 && grid[row - 1][col] != '1')
				return (false);
			while (row < height && grid[row][col] == ' ')
				row++;
			if (row < height && grid[row][col] != '1')
				return (false);
		}
		row++;
	}
	return (is_character_valid(grid[height - 1][col], "1 "));
}

/**
 * @brief Validate all rows (horizontal walls)
 */

bool	validate_rows(t_game *game)
{
	int	row;

	row = 0;
	while (row < game->map.height)
	{
		if (!validate_map_row(game->map.grid[row]))
			return (false);
		row++;
	}
	return (true);
}

/**
 * @brief Validate all columns (vertical walls)
 */

bool	validate_cols(t_game *game)
{
	int	col;

	col = 0;
	while (col < game->map.width)
	{
		if (!validate_map_col(game->map.grid, col, game->map.height))
			return (false);
		col++;
	}
	return (true);
}

/**
 * @brief Comprehensive wall validation
 */

bool	validate_map_walls(t_game *game)
{
	if (!validate_rows(game) || !validate_cols(game))
	{
		free_texture_paths(game);
		return (false);
	}
	return (true);
}
