/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_statistics.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:11:06 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/22 17:17:33 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

static int	process_texture_config(t_game *game, char *config_line)
{
	if (!ft_strncmp(config_line, "NO ", 3))
		extract_texture(game, &game->textures.north.path,
			ft_split(config_line, ' '));
	else if (!ft_strncmp(config_line, "SO ", 3))
		extract_texture(game, &game->textures.south.path,
			ft_split(config_line, ' '));
	else if (!ft_strncmp(config_line, "WE ", 3))
		extract_texture(game, &game->textures.west.path,
			ft_split(config_line, ' '));
	else if (!ft_strncmp(config_line, "EA ", 3))
		extract_texture(game, &game->textures.east.path,
			ft_split(config_line, ' '));
	else
		return (0);
	return (1);
}

static int	process_color_config(t_game *game, char *config_line)
{
	if (!ft_strncmp(config_line, "F ", 2))
		extract_rgb_colors(game, game->map.floor_rgb,
			ft_split(config_line, ' '));
	else if (!ft_strncmp(config_line, "C ", 2))
		extract_rgb_colors(game, game->map.ceiling_rgb,
			ft_split(config_line, ' '));
	else
		return (0);
	return (1);
}

/**
 * @brief Extract configuration data from a single line
 */

int	extract_map_statistics(t_game *game, char *config_line)
{
	static int	elements_processed = 0;

	while (elements_processed < 6)
	{
		if (config_line[0] == ' ' && !config_line[1])
			return (0);
		if (process_texture_config(game, config_line)
			|| process_color_config(game, config_line))
		{
			elements_processed++;
			return (0);
		}
		handle_parsing_error(game, "Error\nInvalid configuration element\n");
	}
	validate_configuration_completeness(game);
	return (1);
}
