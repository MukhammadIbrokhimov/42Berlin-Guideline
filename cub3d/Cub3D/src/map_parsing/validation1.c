/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 01:39:51 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/13 01:51:05 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

/**
 * Validate the player position in the map
 * Checks if there is exactly one player in the map and sets the player's position and direction
 * @param map Pointer to the game structure containing the map
 * @return true if the player is valid, false otherwise
 */

bool	validate_player(t_game *map)
{
	int	i;
	int	j;
	int	player_count;

	i = -1;
	player_count = 0;
	while (++i < map->map_height && map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == NORTH || map->map[i][j] == SOUTH ||
				map->map[i][j] == EAST || map->map[i][j] == WEST)
			{
				player_count++;
				if (player_count > 1)
					return (print_error("Multiple players found"), false);
				map->player.x = j + 0.5;
				map->player.y = i + 0.5;
				map->player.direction = map->map[i][j];
			}
			j++;
		}
	}
	return (true);
}
