/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:37:09 by gansari           #+#    #+#             */
/*   Updated: 2025/08/21 14:40:07 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	calculate_coordinates(t_game *game, int line_start, int line_height)
{
	if (game->ray.side == 0)
	{
		game->wall.hit_x = game->player.pos_y + 
			game->ray.perp_wall_dist * game->ray.dir_y;
	}
	else
	{
		game->wall.hit_x = game->player.pos_x + 
			game->ray.perp_wall_dist * game->ray.dir_x;
	}
	game->wall.hit_x -= floor(game->wall.hit_x);
	game->wall.tex_x = (int)(game->wall.hit_x * TEXTURE_SIZE);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		game->wall.tex_x = TEXTURE_SIZE - game->wall.tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		game->wall.tex_x = TEXTURE_SIZE - game->wall.tex_x - 1;
	game->wall.tex_step = 1.0 * TEXTURE_SIZE / line_height;
	game->wall.tex_pos = (line_start - game->mlx.height / 2 + 
			line_height / 2) * game->wall.tex_step;
}

static int	determine_wall_texture(t_game *game)
{
	if (game->ray.side == 1)
	{
		if (game->ray.dir_y < 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	else
	{
		if (game->ray.dir_x < 0)
			return (WEST);
		else
			return (EAST);
	}
}

void	draw_wall_pixel(t_game *game, int screen_x, 
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
	calculate_coordinates(game, game->wall.draw_start, line_height);
	texture_index = determine_wall_texture(game);
	while (game->wall.draw_start < game->wall.draw_end)
	{
		game->wall.tex_y = (int)game->wall.tex_pos & (TEXTURE_SIZE - 1);
		game->wall.tex_pos += game->wall.tex_step;
		draw_wall_pixel(game, screen_x, game->wall.draw_start, texture_index);
		game->wall.draw_start++;
	}
}
