/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:57:46 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/29 12:39:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_nextline/get_next_line.h"
# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "key.h"

// Color Definitions with Real Names
# define TEXT_COLOR			0xEAEAEA  // Light Gray
# define BACKGROUND			0x222222  // Charcoal
# define MENU_BACKGROUN		0x1E1E1E  // Dark Slate Gray

# define COLOR_DISCO			0x9A1F6A  // Disco Purple
# define COLOR_BRICK_RED		0xC2294E  // Brick Red
# define COLOR_FLAMINGO			0xEC4B27  // Flamingo Orange
# define COLOR_JAFFA			0xEF8633  // Jaffa Orange
# define COLOR_SAFFRON			0xF3AF3D  // Saffron Yellow
# define COLOR_white			0xFFFFFF  // Saffron Yellow
# define WIN_WIDTH 1800
# define WIN_HEIGHT 900
# define M_PI 3.14159265358979323846
# define MAX_KEYS 65536

typedef		struct
{
	int		depth;
	int		offset_x;
	int		offset_y;
	int		zoom;
	int		shift_up;
	int		shift_down;
	int		shift_right;
	int		shift_left;
	int		key_states[MAX_KEYS];
} control;

typedef		struct
{
	int		z1;
	int		z2;
	int		dx;
	int		dy;
	int		iso;
} pixels;

typedef		struct
{
	int		height;
	int		width;
	int		**render_map;
}	map;

typedef		struct
{
	control	window;
	pixels	side;
	map		map;
	int		b_per_pixel;
	int		color;
	int		size_line;
	int		endian;
	char	*address_data;
	void	*mlx;
	void	*wnd;
	void	*img;
}			fdf;



// control functions
void	up_or_down(fdf *map, int command);
void	left_or_right(fdf *map, int command);
// file rendering functions
fdf		*readfile(fdf	*map, char **file);
int		get_size(int *height, char *file, int *width);
int		**allocate(int height, int width, char **file);
int		*fill_map(int *map_line, int width, char *line);
// helper functions
unsigned int	get_color(int z1, int z2);
int		color(float *brightness, int y1, int x1);
int		handle_keyboard(int command, fdf *data);
int		handle_mouse(int button, int x, int y, fdf *data);
void	free_arr(char **str);
void	free_map(int **arr);
void	ft_print(int **map, int height, int width);
void	ft_close(fdf *map);
fdf		*ft_lst(void);
void	ft_swap(float *a, float *b);
void	draw_usage(fdf *data);
// movement control
int		handle_keypress(int key, fdf *data);
int		handle_keyrelease(int key, fdf *data);
void	update_keys(fdf *data);
void	zoom_in_out(fdf *data);
void	add_isometric(fdf *data, int command);
// draw
void	draw_map(fdf *map);
void	set_pixels(fdf	*data);
void	put_pixel(fdf *data, int x, int y, int color);
void	line(int x1, int y1, int x2, int y2, fdf *data);
void	positive_slope(int x1, int y1, fdf *data);
void	negative_slope(int x1, int y1, fdf *data);
void	put_pixel_less(fdf *data, int x, int y);
void	put_pixel_big(fdf *data, int x, int y);
void	reproduce_pixels(int *x1, int *x2, int *y1, int *y2, fdf *data);
void	locate(int *x1, int *x2, int *y1, int *y2, fdf *data);
void	set_background(fdf *data, int color);
void	isometric(int *x, int *y, int z);
// tester
//void	draw_map(fdf *map);
//void	project_isometric(float *x, float *y, int *z, fdf *map);
//void	draw_map(fdf *map);
//void	wu_line(fdf *map, float x1, float y1, float x2, float y2);
//void	wu_line(float x1, float y1, float x2, float y2, fdf *map);
//void	plot_pixel(fdf *data, int x, int y, float intensity);
//float	reverse_fractional_part(float x);
//float	fractional_part(float x);
//void	DDA(int x1, int y1, int x2, int y2, fdf *map);
//void	draw_3d_map(int x1, int y1, int x2, int y2, fdf *map);
//void to_isometric(float *x, float *y, int z);
//void	draw_line(fdf *map, int x1, int y1, int x2, int y2, int color);

#endif
