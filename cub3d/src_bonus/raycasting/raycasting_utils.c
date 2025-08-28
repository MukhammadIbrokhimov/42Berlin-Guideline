/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:53:26 by gansari           #+#    #+#             */
/*   Updated: 2025/08/22 15:44:24 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

static t_image	*get_texture_by_index(t_game *game, int texture_index)
{
	if (texture_index == NORTH)
		return (&game->textures.north);
	else if (texture_index == SOUTH)
		return (&game->textures.south);
	else if (texture_index == EAST)
		return (&game->textures.east);
	else if (texture_index == WEST)
		return (&game->textures.west);
	return (&game->textures.north);
}

int	get_texture_color(t_game *game, int texture_x, int texture_y,
	int texture_index)
{
	char		*pixel_address;
	t_image		*texture;

	texture = get_texture_by_index(game, texture_index);
	pixel_address = texture->data
		+ (texture_y * texture->line_length
			+ texture_x * (texture->bits_per_pixel / 8));
	return (*(int *)pixel_address);
}
