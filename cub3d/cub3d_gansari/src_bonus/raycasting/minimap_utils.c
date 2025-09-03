/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:56:19 by gansari           #+#    #+#             */
/*   Updated: 2025/09/01 12:45:48 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

static void	draw_bold_pixel(t_game *game, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			put_pixel_to_minimap(game, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}
}

static int	should_break_line(t_game *game, double line_x, double line_y)
{
	if (line_x < 0 || line_y < 0 || line_x >= game->map.width
		|| line_y >= game->map.height)
		return (1);
	if (game->map.grid[(int)line_y][(int)line_x] == '1')
		return (1);
	return (0);
}

static void	draw_direction_steps(t_game *game, double line_x,
	double line_y)
{
	double	step_x;
	double	step_y;
	int		i;

	step_x = game->player.dir_x * 0.2;
	step_y = game->player.dir_y * 0.2;
	i = 0;
	while (i < 15)
	{
		draw_bold_pixel(game, (int)(line_x * MINIMAP_SCALE),
			(int)(line_y * MINIMAP_SCALE), 0xFF0000);
		line_x += step_x;
		line_y += step_y;
		if (should_break_line(game, line_x, line_y))
			break ;
		i++;
	}
}

void	draw_player_direction_line(t_game *game)
{
	double	line_x;
	double	line_y;

	line_x = game->player.pos_x;
	line_y = game->player.pos_y;
	draw_direction_steps(game, line_x, line_y);
}
