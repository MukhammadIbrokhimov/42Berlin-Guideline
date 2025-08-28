/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:47:09 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/21 14:00:12 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

int	parse_and_validate_rgb_values(int *rgb, char *rgb_line)
{
	char	**parts;
	int		n;
	int		i;
	int		val;

	if (!validate_rgb_line_format(rgb_line))
		return (0);
	parts = ft_split(rgb_line, ',');
	if (!parts)
		return (0);
	n = count_elems(parts);
	if (n != 3)
		return (free_string_array(parts), 0);
	i = -1;
	while (++i < 3)
	{
		strip_trailing_nl(parts[i]);
		if (!is_number(parts[i]))
			return (free_string_array(parts), 0);
		val = ft_atoi(parts[i]);
		if (val < 0 || val > 255)
			return (free_string_array(parts), 0);
		rgb[i] = val;
	}
	return (free_string_array(parts), 1);
}

void	extract_rgb_colors(t_game *game, int *rgb, char **split_line)
{
	int	n;

	n = count_elems(split_line);
	if (n >= 1)
		strip_trailing_nl(split_line[n - 1]);
	if (n != 2)
	{
		free_string_array(split_line);
		handle_parsing_error(game, "Error\nInvalid color definition format\n");
	}
	if (!parse_and_validate_rgb_values(rgb, split_line[1]))
	{
		free_string_array(split_line);
		handle_parsing_error(game,
			"Error\nInvalid RGB color values (must be 0-255)\n");
	}
	free_string_array(split_line);
}
