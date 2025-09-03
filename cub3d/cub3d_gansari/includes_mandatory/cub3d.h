/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:25:55 by gansari           #+#    #+#             */
/*   Updated: 2025/09/01 17:44:57 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/*                               INCLUDES                                     */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include "keys.h"
# include "game_struct.h"
# include "../Libft/libft.h"

/* Map characters */
//# define WALL '1'
//# define EMPTY '0'
//# define NORTHH 'N'
//# define SOUTHH 'S'
//# define EASTT 'E'
//# define WESTT 'W'
//# define SPACE ' '
# define MAX_MAP_LINES 1000

/* Error messages */
# define ERR_FILE_EXT "File must have .cub extension"
# define ERR_FILE_OPEN "Cannot open file"
# define ERR_MALLOC "Memory allocation failed"
# define ERR_INVALID "Invalid map"
# define ERR_NO_PLAYER "No player found in map"
# define ERR_MULTI_PLAYER "Multiple players found"
# define ERR_MAP_NOT_CLOSED "Error\nMap is not surrounded by walls\n"
# define ERR_INVALID_CHAR "Invalid character in map"
# define ERR_MISSING_TEXTURE "Missing texture path"
# define ERR_INVALID_COLOR "Invalid color format"
# define ERR_INVALID_MAP "Error\nInvalid character '/' found in map data\n"

/* ************************************************************************** */
/*                               CONSTANTS                                    */
/* ************************************************************************** */

/* Window and display settings */
# define DEFAULT_WIDTH	1940	/* Default window width */
# define DEFAULT_HEIGHT	1280	/* Default window height */
# define TEXTURE_SIZE	128		/* Size of wall textures (128x128) */

/* Movement and rotation speeds */
# define MOVE_SPEED		0.04	/* Player movement speed */
# define ROTATION_SPEED	0.04	/* Player rotation speed */

/* Minimap settings */
# define MINIMAP_SCALE	7		/* Scale factor for minimap */
# define MINIMAP_OFFSET	10		/* Offset from window edge */

/* Colors for minimap and UI */
# define COLOR_BLACK	0x000000	/* Black color */
# define COLOR_WHITE	0xFFFFFF	/* White color */
# define COLOR_PLAYER	0xEEEE20	/* Player color on minimap */
# define COLOR_WALL		0x050505	/* Wall color on minimap */

/* ************************************************************************** */
/*                               ENUMERATIONS                                 */
/* ************************************************************************** */

/**
 * @brief Cardinal directions for wall textures
 */
enum e_direction
{
	NORTH = 0,	
	SOUTH = 1,	
	EAST = 2,
	WEST = 3
};

typedef struct s_scan_data
{
	t_game	*game;
	int		row;
	int		base;
	int		*player_count;
}	t_scan_data;

/* ************************************************************************** */
/*                           FUNCTION PROTOTYPES                             */
/* ************************************************************************** */

/* ========================================================================== */
/*                               MAIN FUNCTIONS                              */
/* ========================================================================== */

void	init_game_structure(t_game *game);

/* ========================================================================== */
/*                            VALIDATION FUNCTIONS                           */
/* ========================================================================== */
int		is_valid_file_descriptor(int fd);
int		validate_arguments(int argc, char **argv);
int		is_parseable_map_file(t_game *game, int fd);
int		validate_input_file(char *filename);
bool	validate_open_walls(t_game *game);
int		free_double_ptr(char **ptr);
char	**create_temp_map(t_map *game);
int		flood_fill(char **map, int y, int x, t_map *game);
void	print_error(char *message);

/* ========================================================================== */
/*                            MEMORY MANAGEMENT                              */
/* ========================================================================== */

void	destroy_mlx_images(t_game *game);
void	cleanup_mlx_resources(t_game *game);
void	free_texture_paths(t_game *game);
void	free_string_array(char **array);
void	free_parsing_buffers(t_game *game);
int		clean_exit_program(t_game *game);

/* ========================================================================== */
/*                            PARSING FUNCTIONS                              */
/* ========================================================================== */

void	handle_parsing_error(t_game *game, char *error_message);
int		read_and_parse_map_file(int file_descriptor, t_game *game);
int		parse_map_file(t_game *game, int file_descriptor);
void	normalize_map_dimensions(t_game *g);

/* ========================================================================== */
/*                            PARSING UTILITIES                              */
/* ========================================================================== */

int		is_character_valid(char character, char *valid_chars);
int		is_number(const char *s);
int		count_elems(char **v);
int		get_string_length_no_newline(char *string);
char	*resize(char *org_str, int target_size);
char	*join_strings(char *first_string, char *second_string);
int		count_elems(char **v);
void	strip_trailing_nl(char *s);
int		is_number(const char *s);

/* ========================================================================== */
/*                          WALL VALIDATION                                  */
/* ========================================================================== */

int		validate_map_column(char **map_array, int row, int col, int total_rows);
int		validate_vertical_walls(t_game *game, int start_row, int start_col);
int		validate_map_line(t_game *game, char *line_to_check, int start_col);
int		validate_horizontal_walls(t_game *game, int start_row, int start_col);
bool	validate_map_walls(t_game *game);
int		validate_parsed_map(t_game *game);

/* ========================================================================== */
/*                          MAP STATISTICS                                   */
/* ========================================================================== */

void	set_player_position_and_direction(t_game *game, char direction,
			int row, int col);
void	calculate_map_dimensions(t_game *game, char **map_array,
			int start_row, int start_col);
int		extract_map_statistics(t_game *game, char *config_line);
void	validate_configuration_completeness(t_game *game);

/* ========================================================================== */
/*                        RGB AND TEXTURE PARSING                           */
/* ========================================================================== */

void	extract_texture_path(t_game *game, char **texture_path,
			char **split_line);
void	extract_texture(t_game *game, char **tex_path, char **split_line);
int		validate_rgb_line_format(char *rgb_line);
void	extract_rgb_colors(t_game *game, int *rgb_array, char **split_line);
int		parse_and_validate_rgb_values(int *rgb, char *rgb_line);

/* ========================================================================== */
/*                             GAME INITIALIZATION                           */
/* ========================================================================== */

void	handle_game_error(t_game *game, char *error_message);
void	init_game_settings(t_game *game);
void	init_mlx_images(t_game *game);
int		init_game_engine(t_game *game);

/* ========================================================================== */
/*                           INPUT HANDLING                                  */
/* ========================================================================== */

int		handle_keyboard_input(int keycode, t_game *game);
int		handle_mouse_rotation(int mouse_x, int mouse_y, t_game *game);
int		handle_mouse_rotation(int mouse_x, int mouse_y, t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
void	process_movement_input(t_game *game);

/* ========================================================================== */
/*                           PLAYER MOVEMENT                                 */
/* ========================================================================== */

void	move_player_with_collision(t_game *game, double delta_x,
			double delta_y);
void	rotate_player_view(t_game *game, double rotation_speed);
void	handle_diagonal_movement(t_game *game, double new_x, double new_y);
void	handle_single_axis_movement(t_game *game, double delta_x,
			double delta_y);
void	revert_invalid_position(t_game *game, double delta_x, double delta_y);
int		is_wall_at_position(t_game *game, int x, int y);

/* ========================================================================== */
/*                            RAYCASTING ENGINE                              */
/* ========================================================================== */

void	calculate_delta_distances(t_game *game);
void	calculate_step_and_side_distances(t_game *game);
void	execute_dda_algorithm(t_game *game);
void	init_raycasting_for_column(t_game *game, int screen_x);
void	execute_raycasting(t_game *game);

/* ========================================================================== */
/*                            RENDERING UTILITIES                            */
/* ========================================================================== */

int		get_texture_color(t_game *game, int tex_x, int tex_y,
			int texture_index);

/* ========================================================================== */
/*                              DRAWING FUNCTIONS                            */
/* ========================================================================== */

void	put_pixel_to_image(t_game *game, int x, int y, int color);
void	draw_wall_column(t_game *game, int screen_x);
int		render_frame(t_game *game);
void	calculate_texture_coordinates(t_game *game, int line_start,
			int line_height);

/* ========================================================================== */
/*                           BACKGROUND RENDERING                            */
/* ========================================================================== */

int		create_trgb_color(int transparency, int red, int green, int blue);
void	render_background_colors(t_game *game);

#endif