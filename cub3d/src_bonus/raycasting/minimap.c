/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:53:00 by gansari           #+#    #+#             */
/*   Updated: 2025/08/25 11:57:33 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

static int	get_cell_color(t_game *game, char cell_char)
{
	if (cell_char == '1')
		return (COLOR_BLACK);
	else if (cell_char == '0' || is_character_valid(cell_char, "NSEW"))
		return (create_trgb_color(0, game->map.ceiling_rgb[0],
				game->map.ceiling_rgb[1], game->map.ceiling_rgb[2]));
	else
		return (COLOR_WALL);
}

void	draw_minimap_display(t_game *game)
{
	int	row_index;
	int	col_index;

	row_index = 0;
	while (game->map.grid[row_index])
	{
		col_index = 0;
		while (game->map.grid[row_index][col_index])
		{
			draw_minimap_case(game, col_index * MINIMAP_SCALE,
				row_index * MINIMAP_SCALE,
				get_cell_color(game, game->map.grid[row_index][col_index]));
			col_index++;
		}
		row_index++;
	}
}

void	update_minimap_player_position(t_game *game, int previous_x,
		int previous_y)
{
	int	background_color;

	draw_minimap_case(game, (int)game->player.pos_x * MINIMAP_SCALE,
		(int)game->player.pos_y * MINIMAP_SCALE, COLOR_PLAYER);
	if ((int)game->player.pos_x != previous_x
		|| (int)game->player.pos_y != previous_y)
	{
		if (game->map.grid[previous_y][previous_x] == '1')
			background_color = COLOR_BLACK;
		else
			background_color = create_trgb_color(0, game->map.ceiling_rgb[0],
					game->map.ceiling_rgb[1], game->map.ceiling_rgb[2]);
		draw_minimap_case(game, previous_x * MINIMAP_SCALE,
			previous_y * MINIMAP_SCALE, background_color);
	}
}

void	put_pixel_to_minimap(t_game *game, int x, int y, int color)
{
	char	*pixel_address;

	if (y < 0 || y >= game->mlx.height || x < 0 || x >= game->mlx.width)
		return ;
	pixel_address = game->textures.minimap.data
		+ (y * game->textures.minimap.line_length
			+ x * (game->textures.minimap.bits_per_pixel / 8));
	*(int *)pixel_address = color;
}

void	draw_minimap_case(t_game *game, int start_x, int start_y, int color)
{
	int	pixel_row;
	int	pixel_col;

	pixel_row = 0;
	while (pixel_row < MINIMAP_SCALE)
	{
		pixel_col = 0;
		while (pixel_col < MINIMAP_SCALE)
		{
			put_pixel_to_minimap(game, start_x + pixel_col,
				start_y + pixel_row, color);
			pixel_col++;
		}
		pixel_row++;
	}
}
