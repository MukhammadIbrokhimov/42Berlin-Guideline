/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:46:40 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/28 12:01:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

void	print_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (EXIT_FAILURE);
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (EXIT_SUCCESS);
}

/**
 * Validate the map structure
 * Checks if the map is rectangular, has valid characters, and is closed
 * @param game Pointer to the game structure containing the map
 * @return true if the map is valid, false otherwise
 */

bool	validate_open_walls(t_game *game)
{
	char	**temp_map;
	bool	result;

	temp_map = create_temp_map(&game->map);
	if (!temp_map)
		return (false);
	result = flood_fill(temp_map, (int)game->player.pos_y,
			(int)game->player.pos_x, &game->map);
	free_double_ptr(temp_map);
	if (!result)
		return (print_error(ERR_MAP_NOT_CLOSED), false);
	return (true);
}

/**
 * Create a temporary copy of the map for flood fill
 * Normalize all lines to the same width (pad with spaces)
 */

char	**create_temp_map(t_map *game)
{
	char	**temp_map;
	int		i;
	int		j;

	i = -1;
	temp_map = malloc(sizeof(char *) * (game->height + 1));
	if (!temp_map)
		return (NULL);
	while (++i < game->height)
	{
		temp_map[i] = malloc(sizeof(char) * (game->width + 1));
		if (!temp_map[i])
			return (free_double_ptr(temp_map), NULL);
		j = -1;
		while (++j < game->width)
		{
			if (j < (int)ft_strlen(game->grid[i]) && game->grid[i][j] != '\n')
				temp_map[i][j] = game->grid[i][j];
			else
				temp_map[i][j] = ' ';
		}
		temp_map[i][game->width] = '\0';
	}
	return (temp_map[game->height] = NULL, temp_map);
}

/**
 * Flood fill algorithm to check wall closure
 * Returns 0 if any empty space reaches the border
 */

int	flood_fill(char **map, int y, int x, t_map *game)
{
	if (y < 0 || y >= game->height || x < 0 || x >= game->width)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'X')
		return (1);
	if (map[y][x] == ' ' && (y == 0 || y == game->height - 1 || 
		x == 0 || x == game->width - 1))
		return (0);
	map[y][x] = 'X';
	if (!flood_fill(map, y - 1, x, game)
		|| !flood_fill(map, y + 1, x, game)
		|| !flood_fill(map, y, x - 1, game)
		|| !flood_fill(map, y, x + 1, game))
		return (0);
	return (1);
}
