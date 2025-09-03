/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:49:35 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/30 19:23:45 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

int	validate_parsed_map(t_game *game)
{
	if (!validate_map_walls(game))
	{
		ft_printf("Error\nMap is not properly enclosed by walls\n");
		return (0);
	}
	return (1);
}

void	handle_parsing_error(t_game *game, char *error_message)
{
	ft_printf("%s", error_message);
	if (game->map.grid)
		free_string_array(game->map.grid);
	if (game->map.current_line)
		free(game->map.current_line);
	if (game->map.data_buffer)
		free(game->map.data_buffer);
	free_texture_paths(game);
	exit(EXIT_FAILURE);
}

void	normalize_map_dimensions(t_game *g)
{
	int	i;

	calculate_map_dimensions(g, g->map.grid, 0, 0);
	if (!g->map.height || !g->map.width)
		handle_parsing_error(g, ERR_INVALID_MAP);
	i = 0;
	while (g->map.grid[i])
	{
		if (get_string_length_no_newline(g->map.grid[i]) < g->map.width)
		{
			g->map.grid[i] = resize(g->map.grid[i], g->map.width);
			if (!g->map.grid[i])
				handle_parsing_error(g, ERR_MALLOC);
		}
		i++;
	}
}

static int	process_map_line(t_game *g, char *line, int *parsing)
{
	g->map.current_line = line;
	if (line[0] == '\n')
		line[0] = ' ';
	if (!*parsing)
		*parsing = extract_map_statistics(g, line);
	if (*parsing && ft_strchr(line, '/'))
	{
		free(line);
		g->map.current_line = NULL;
		return (handle_parsing_error(g, ERR_INVALID_MAP), 0);
	}
	if (*parsing)
		g->map.data_buffer = join_strings(g->map.data_buffer, line);
	free(line);
	g->map.current_line = NULL;
	return (1);
}

int	read_and_parse_map_file(int fd, t_game *g)
{
	char	*line;
	int		parsing;
	char	*buffer;

	parsing = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!process_map_line(g, line, &parsing))
			return (0);
		line = get_next_line(fd);
	}
	buffer = "";
	if (g->map.data_buffer)
		buffer = g->map.data_buffer;
	g->map.grid = ft_split(buffer, '/');
	return (free(g->map.data_buffer), g->map.data_buffer = NULL, 1);
}
