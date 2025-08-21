/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:53:26 by gansari           #+#    #+#             */
/*   Updated: 2025/08/21 14:43:33 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	get_texture_color(t_game *game, int x, int y, int texture_index)
{
	char		*pixel_address;
	t_image		*texture;

	texture = get_texture_by_index(game, texture_index);
	pixel_address = texture->data
		+ (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(int *)pixel_address);
}
