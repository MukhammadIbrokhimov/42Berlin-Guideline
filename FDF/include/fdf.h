/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:57:46 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/28 13:26:05 by mukibrok         ###   ########.fr       */
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
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define M_PI 3.14159265358979323846
# define MAX(a, b) ((a > b) ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

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
} control;

typedef		struct
{
	int		z1;
	int		z2;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		dx;
	int		dy;
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
int		color(float *brightness, int y1, int x1);
int		do_commands(int	command, fdf *map);
void	free_arr(char **str);
void	free_map(int **arr);
void	ft_print(int **map, int height, int width);
void	ft_close(fdf *map);
fdf		*ft_lst(void);
void	ft_swap(float *a, float *b);
// draw
unsigned int get_color(int z1, int z2);
void	draw_map(fdf *map);
void	set_pixels(fdf	*data);
void	put_pixel(fdf *data, int x, int y);
void	line(int x1, int y1, int x2, int y2, fdf *data);
void	positive_slope(int x1, int y1, fdf *data);
void	negative_slope(int x1, int y1, fdf *data);
void	put_pixel_less(fdf *data, int x, int y);
void	put_pixel_big(fdf *data, int x, int y);

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
