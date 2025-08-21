/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 23:59:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/13 01:41:07 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/Cub3D.h"

/*
 * Parse the width of the map
 * This function iterates through each line of the map and calculates the maximum width.
*/

int	parse_width(t_game *map)
{
	int	width_len;
	int	i;

	if (!map || !map->map || map->map_height == 0)
		return (print_error("Map is not initialized"), EXIT_FAILURE);
	i = 0;
	while (i < map->map_height && map->map[i])
	{
		width_len = ft_strlen(map->map[i]);
		if (width_len > map->map_width)
			map->map_width = width_len;
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
 * Parse a color from a string in the format "F 255,255,255" or "C 255,255,255"
 * @param line The line containing the color information
 * @return A t_color struct with the parsed RGB values, or (-1, -1, -1) on error
*/

t_color	parse_color(char *line)
{
	t_color	color;
	char	**split;

	split = ft_split(line + 2, ',');
	if (split_len(split) != 3)
		return (free_double_ptr(split), (t_color){-1, -1, -1});
	color.red = ft_atoi(split[0]);
	color.green = ft_atoi(split[1]);
	color.blue = ft_atoi(split[2]);
	free_double_ptr(split);
	return (color);
}

/*
 * Parse a texture line and store the texture path in the game map structure
 * @param line The line containing the texture information
 * @param map Pointer to the game structure to store the texture
 * @return EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */

int	parse_texture(char *line, t_game *map)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		map->textures[NORTH_TEX] = ft_strdup(line + space_count(line));
	if (ft_strncmp(line, "SO ", 3) == 0)
		map->textures[SOUTH_TEX] = ft_strdup(line + space_count(line));
	if (ft_strncmp(line, "WE ", 3) == 0)
		map->textures[WEST_TEX] = ft_strdup(line + space_count(line));
	if (ft_strncmp(line, "EA ", 3) == 0)
		map->textures[EAST_TEX] = ft_strdup(line + space_count(line));
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * Parse the map file and store the map and textures in the game structure
 * @param map Pointer to the game structure to store the map and textures
 * @param filename The name of the file to parse
 * @return EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */

int	parse_file(t_game *map, char *filename)
{
	int		fd;
	char	*line;
	int		map_started;

	map_started = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error("Error opening file"), EXIT_FAILURE);
	while ((line = get_next_line(fd)))
	{
		if (!map_started && (line[0] == '0' || line[0] == '1' || line[0] == ' '))
		{
			map_started = 1;
			if (parse_map_line(line, map, fd) == EXIT_FAILURE)
				return (print_error("Invalid map"), free(line), EXIT_FAILURE);
		}
		parse_texture(line, map);
		if (line[0] == 'F')
			map->floor_color = parse_color(line);
		if (line[0] == 'C')
			map->ceiling_color = parse_color(line);
		free(line);
	}
	return (close(fd), EXIT_SUCCESS);
}

/*
 * Parse a line of the map and store it in the game structure
 * @param line The line to parse
 * @param map Pointer to the game structure to store the map
 * @param fd File descriptor of the map file
 * @return EXIT_SUCCESS if successful, EXIT_FAILURE if an error occurs
 */

int	parse_map_line(char *line, t_game *map, int fd)
{
	char	**map_lines;
	int		map_line_count;

	map_line_count = 0;
	map_lines = NULL;
	map_lines = malloc(sizeof(char *) * (MAX_MAP_LINES + 1)); 
	if (!map_lines)
		return (EXIT_FAILURE);
	map_lines[map_line_count++] = ft_strdup(line);
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) == 0 || line[0] == '\n')
		{
			free(line);
			break ;
		}
		map_lines[map_line_count++] = ft_strdup(line);
		free(line);
	}
	map_lines[map_line_count] = NULL;
	map->map = map_lines;
	map->map_height = map_line_count;
	if (parse_width(map) == EXIT_FAILURE)
		return (free_double_ptr(map->map), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
