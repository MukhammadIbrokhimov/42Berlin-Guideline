/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_on_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:19:32 by gansari           #+#    #+#             */
/*   Updated: 2025/08/30 00:14:12 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

static int	is_ray_out_of_bounds(t_game *game, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0)
		return (1);
	if (map_x >= game->map.width || map_y >= game->map.height)
		return (1);
	return (0);
}

static int	is_wall_hit(t_game *game, int map_x, int map_y)
{
	if (is_ray_out_of_bounds(game, map_x, map_y))
		return (1);
	if (game->map.grid[map_y][map_x] == '1')
		return (1);
	return (0);
}

static void	draw_ray_pixel(t_game *game, double ray_x, double ray_y)
{
	int	pixel_x;
	int	pixel_y;

	pixel_x = (int)(ray_x * MINIMAP_SCALE);
	pixel_y = (int)(ray_y * MINIMAP_SCALE);
	put_pixel_to_minimap(game, pixel_x, pixel_y, 0xFF0000);
}

static void	update_ray_position(double *ray_x, double *ray_y,
	double ray_dir_x, double ray_dir_y)
{
	double	step;

	step = 0.1;
	*ray_x += ray_dir_x * step;
	*ray_y += ray_dir_y * step;
}

void	draw_ray_on_minimap(t_game *game, double ray_dir_x, double ray_dir_y)
{
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		i;

	ray_x = game->player.pos_x;
	ray_y = game->player.pos_y;
	i = 0;
	while (i < 150)
	{
		map_x = (int)ray_x;
		if (is_wall_hit(game, map_x, (int)ray_y))
			break ;
		draw_ray_pixel(game, ray_x, ray_y);
		update_ray_position(&ray_x, &ray_y, ray_dir_x, ray_dir_y);
		i++;
	}
}
