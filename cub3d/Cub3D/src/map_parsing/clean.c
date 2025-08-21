/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:46:12 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/13 00:18:25 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cub3D.h"

/**
 * Free the allocated memory for the map and textures
 * @param map Pointer to the game structure containing the map and textures
 */

void	cleanup_map(t_game *map)
{
	if (!map)
		return ;
	if (map->map)
		free_double_ptr(map->map);
	int i = -1;
	while (++i < TEX_COUNT)
	{
		if (map->textures[i])
			free(map->textures[i]);
	}
}
