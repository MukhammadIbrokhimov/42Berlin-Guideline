/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:37:09 by gansari           #+#    #+#             */
/*   Updated: 2025/09/01 17:43:15 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_mandatory/cub3d.h"

static void	calculate_wall_line_parameters(t_game *game, int *line_height,
		int *start_y, int *end_y)
{
	*line_height = (int)(game->mlx.height / game->ray.perp_wall_dist);
	*start_y = (-(*line_height) / 2) + (game->mlx.height / 2);
	*end_y = ((*line_height) / 2) + (game->mlx.height / 2);
	if (*start_y < 0)
		*start_y = 0;
	if (*end_y >= game->mlx.height)
		*end_y = game->mlx.height - 1;
}

static int	determine_wall_texture(t_game *game)
{
	if (game->ray.side == 1)
	{
		if (game->ray.dir_y < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (game->ray.dir_x < 0)
			return (WEST);
		else
			return (EAST);
	}
}

static void	draw_textured_wall_pixel(t_game *game, int screen_x,
		int screen_y, int texture_index)
{
	int	pixel_color;

	pixel_color = get_texture_color(game, game->wall.tex_x,
			game->wall.tex_y, texture_index);
	put_pixel_to_image(game, screen_x, screen_y, pixel_color);
}

void	draw_wall_column(t_game *game, int screen_x)
{
	int	line_height;
	int	texture_index;

	calculate_wall_line_parameters(game, &line_height,
		&game->wall.draw_start, &game->wall.draw_end);
	calculate_texture_coordinates(game, game->wall.draw_start, line_height);
	texture_index = determine_wall_texture(game);
	while (game->wall.draw_start < game->wall.draw_end)
	{
		game->wall.tex_y = (int)game->wall.tex_pos & (TEXTURE_SIZE - 1);
		game->wall.tex_pos += game->wall.tex_step;
		draw_textured_wall_pixel(game, screen_x, game->wall.draw_start,
			texture_index);
		game->wall.draw_start++;
	}
}
