/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 00:22:05 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/13 01:53:36 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

/**
 * Validate the file extension of the given filename
 * @param filename The name of the file to validate
 * @return true if the file has a valid .cub extension, false otherwise
 */

bool	validate_file_extension(char *filename)
{
	char	*ext;
	size_t		len;
	size_t		ext_len;

	ext = ".cub";
	len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (len < ext_len)
		return (false);
	return (ft_strcmp(filename + len - ext_len, ext) == 0);
}

/**
 * Validate the textures in the game map structure
 * @param map Pointer to the game structure containing the textures
 * @return true if all textures are valid, false otherwise
 */

bool	validate_texture(t_game *map)
{
	if (!map->textures[NORTH_TEX] || !map->textures[SOUTH_TEX] ||
		!map->textures[WEST_TEX] || !map->textures[EAST_TEX])
		return (print_error("Missing texture"), false);
	return (true);
}

/**
 * Validate the color values in a t_color structure
 * @param color The t_color structure to validate
 * @return true if the color values are valid (0-255), false otherwise
 */

bool	validate_color(t_game *map)
{
	t_color	fcolor;
	t_color	ccolor;

	fcolor = map->floor_color;
	ccolor = map->ceiling_color;
	if (fcolor.red < 0 || fcolor.red > 255 ||
		fcolor.green < 0 || ccolor.green > 255 ||
		ccolor.blue < 0 || ccolor.blue > 255)
	{
		print_error("Invalid color values");
		return (false);
	}
	return (true);
}

/**
 * Validate the characters in the map
 * Checks if the map contains only valid characters: WALL, EMPTY, SPACE, NORTH, SOUTH, EAST, WEST
 * @param map Pointer to the game structure containing the map
 * @return true if all characters are valid, false otherwise
 */

bool	validate_char(t_game *map)
{
	int	i;
	int	j;

	i = -1;
	if (!map || !map->map)
		return (print_error("Map is not initialized"), false);
	if (map->map_height <= 0 || map->map_width <= 0)
		return (print_error("Invalid map dimensions"), false);
	while (++i < map->map_height && map->map[i])
	{
		j = -1;
		while (++j < (int)ft_strlen(map->map[i]))
		{
			if (map->map[i][j] != WALL && map->map[i][j] != EMPTY &&
				map->map[i][j] != SPACE && map->map[i][j] != NORTH &&
				map->map[i][j] != SOUTH && map->map[i][j] != EAST &&
				map->map[i][j] != WEST)
				return (print_error("Invalid character in map"), false);
		}
	}
	return (true);
}

/**
 * Validate the map structure and contents
 * @param map Pointer to the game structure containing the map
 * @return true if the map is valid, false otherwise
 */

bool	validate_map(t_game *map)
{
	if ((validate_texture(map) == false) 
		|| (validate_color(map) == false)
		|| (validate_char(map) == false)
		|| (validate_player(map) == false))
		return (false);
	return (true);
}
