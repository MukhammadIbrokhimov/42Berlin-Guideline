/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:25:55 by gansari           #+#    #+#             */
/*   Updated: 2025/08/11 21:20:56 by gansari          ###   ########.fr       */
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
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include "keys.h"
# include "game_struct.h"
# include "../Libft/libft.h"

/* ************************************************************************** */
/*                               CONSTANTS                                    */
/* ************************************************************************** */

/* Window and display settings */
# define DEFAULT_WIDTH	1940	/* Default window width */
# define DEFAULT_HEIGHT	1280	/* Default window height */
# define TEXTURE_SIZE	128		/* Size of wall textures (128x128) */

/* Movement and rotation speeds */
# define MOVE_SPEED		0.09	/* Player movement speed */
# define ROTATION_SPEED	0.09	/* Player rotation speed */

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
 * 
 * Used to identify which texture to apply based on wall orientation
 */
enum e_direction
{
	NORTH = 0,	/* North-facing wall */
	SOUTH = 1,	/* South-facing wall */
	EAST = 2,	/* East-facing wall */
	WEST = 3	/* West-facing wall */
};

/* ************************************************************************** */
/*                           FUNCTION PROTOTYPES                             */
/* ************************************************************************** */

/* ========================================================================== */
/*                               MAIN FUNCTIONS                              */
/* ========================================================================== */

/**
 * @brief Initialize all structure members to zero/NULL
 * @param map Pointer to the main game structure
 */
void	initialize_game_structure(t_map *map);

/**
 * @brief Validate file extension and readability
 * @param filename Path to the .cub file
 * @return 1 if file is valid, 0 otherwise
 */
int		validate_input_file(char *filename);

/* ========================================================================== */
/*                            MEMORY MANAGEMENT                              */
/* ========================================================================== */

/**
 * @brief Destroy all MLX images to prevent memory leaks
 * @param map Pointer to the main game structure
 */
void	destroy_mlx_images(t_map *map);

/**
 * @brief Free all texture paths stored in the structure
 * @param map Pointer to the main game structure
 */
void	free_texture_paths(t_map *map);

/**
 * @brief Free a double array (array of strings)
 * @param array Double pointer to the array to free
 */
void	free_string_array(char **array);

/**
 * @brief Clean exit function - frees all resources and closes window
 * @param map Pointer to the main game structure
 * @return Always returns 0 (for MLX hook compatibility)
 */
int		clean_exit_program(t_map *map);

/* ========================================================================== */
/*                            PARSING FUNCTIONS                              */
/* ========================================================================== */

/**
 * @brief Display error message and exit program cleanly
 * @param map Pointer to the main game structure
 * @param error_message Error message to display
 */
void	handle_parsing_error(t_map *map, char *error_message);

/**
 * @brief Read and parse the entire map file
 * @param file_descriptor Open file descriptor for the .cub file
 * @param map Pointer to the main game structure
 */
void	read_and_parse_map_file(int file_descriptor, t_map *map);

/**
 * @brief Main parsing function - coordinates all parsing operations
 * @param map Pointer to the main game structure
 * @param file_descriptor Open file descriptor for the .cub file
 * @return 1 if parsing successful, 0 otherwise
 */
int		parse_map_file(t_map *map, int file_descriptor);

/* ========================================================================== */
/*                            PARSING UTILITIES                              */
/* ========================================================================== */

/**
 * @brief Check if character is in the list of valid characters
 * @param character Character to check
 * @param valid_chars String containing all valid characters
 * @return 1 if character is valid, 0 otherwise
 */
int		is_character_valid(char character, char *valid_chars);

/**
 * @brief Get string length excluding newline character
 * @param string String to measure
 * @return Length of string without newline
 */
int		get_string_length_no_newline(char *string);

/**
 * @brief Resize string to specified length, padding with spaces
 * @param original_string Original string to resize
 * @param target_size Target size for the new string
 * @return Newly allocated resized string
 */
char	*resize_string_to_size(char *original_string, int target_size);

/**
 * @brief Join two strings with '/' separator for map parsing
 * @param string1 First string (can be NULL)
 * @param string2 Second string to append
 * @return Newly allocated joined string
 */
char	*join_strings_with_separator(char *string1, char *string2);

/* ========================================================================== */
/*                          WALL VALIDATION                                  */
/* ========================================================================== */

/**
 * @brief Check if a column of the map is properly walled
 * @param map_array 2D array representing the map
 * @param row Starting row index
 * @param col Column index to check
 * @param total_rows Total number of rows in the map
 * @return 1 if column is valid, 0 otherwise
 */
int		validate_map_column(char **map_array, int row, int col, int total_rows);

/**
 * @brief Perform vertical wall validation for entire map
 * @param map Pointer to the main game structure
 * @param start_row Starting row for validation
 * @param start_col Starting column for validation
 * @return 1 if vertical walls are valid, 0 otherwise
 */
int		validate_vertical_walls(t_map *map, int start_row, int start_col);

/**
 * @brief Check if a single line of the map is properly walled
 * @param map Pointer to the main game structure
 * @param line_to_check Line string to validate
 * @param start_col Starting column index
 * @return 1 if line is valid, 0 otherwise
 */
int		validate_map_line(t_map *map, char *line_to_check, int start_col);

/**
 * @brief Perform horizontal wall validation for entire map
 * @param map Pointer to the main game structure
 * @param start_row Starting row for validation
 * @param start_col Starting column for validation
 * @return 1 if horizontal walls are valid, 0 otherwise
 */
int		validate_horizontal_walls(t_map *map, int start_row, int start_col);

/**
 * @brief Main wall validation function
 * @param map Pointer to the main game structure
 * @return 1 if all walls are valid, 0 otherwise
 */
int		validate_map_walls(t_map *map);

/* ========================================================================== */
/*                          MAP STATISTICS                                   */
/* ========================================================================== */

/**
 * @brief Set player position and direction based on map character
 * @param map Pointer to the main game structure
 * @param direction Player direction character (N/S/E/W)
 * @param row Row position of player
 * @param col Column position of player
 */
void	set_player_position_and_direction(t_map *map, char direction, int row, int col);

/**
 * @brief Calculate map dimensions and find player position
 * @param map Pointer to the main game structure
 * @param map_array 2D array representing the map
 * @param start_row Starting row for analysis
 * @param start_col Starting column for analysis
 */
void	calculate_map_dimensions(t_map *map, char **map_array, int start_row, int start_col);

/**
 * @brief Extract map statistics from a configuration line
 * @param map Pointer to the main game structure
 * @param config_line Line from the configuration file
 * @return 1 if ready to parse map data, 0 if still parsing config
 */
int		extract_map_statistics(t_map *map, char *config_line);

/* ========================================================================== */
/*                        RGB AND TEXTURE PARSING                           */
/* ========================================================================== */

/**
 * @brief Extract and validate texture path from configuration line
 * @param map Pointer to the main game structure
 * @param texture_path Pointer to store the texture path
 * @param split_line Array of strings from split configuration line
 */
void	extract_texture_path(t_map *map, char **texture_path, char **split_line);

/**
 * @brief Validate RGB color line format
 * @param rgb_line String containing RGB values
 * @return 1 if format is valid, 0 otherwise
 */
int		validate_rgb_line_format(char *rgb_line);

/**
 * @brief Parse and validate RGB color values
 * @param rgb_array Array to store RGB values
 * @param rgb_line String containing RGB values
 * @return 1 if RGB values are valid, 0 otherwise
 */
int		parse_and_validate_rgb(int *rgb_array, char *rgb_line);

/**
 * @brief Extract RGB color values from configuration line
 * @param map Pointer to the main game structure
 * @param rgb_array Array to store RGB values
 * @param split_line Array of strings from split configuration line
 */
void	extract_rgb_colors(t_map *map, int *rgb_array, char **split_line);

/* ========================================================================== */
/*                             GAME INITIALIZATION                           */
/* ========================================================================== */

/**
 * @brief Display game error and exit cleanly
 * @param map Pointer to the main game structure
 * @param error_message Error message to display
 */
void	handle_game_error(t_map *map, char *error_message);

/**
 * @brief Initialize game-specific statistics and settings
 * @param map Pointer to the main game structure
 */
void	initialize_game_statistics(t_map *map);

/**
 * @brief Initialize all MLX images (textures and display buffer)
 * @param map Pointer to the main game structure
 */
void	initialize_mlx_images(t_map *map);

/**
 * @brief Main game initialization function
 * @param map Pointer to the main game structure
 * @return 0 on success
 */
int		initialize_game_engine(t_map *map);

/* ========================================================================== */
/*                           INPUT HANDLING                                  */
/* ========================================================================== */

/**
 * @brief Handle keyboard input events
 * @param keycode Code of the pressed key
 * @param map Pointer to the main game structure
 * @return 0 (for MLX compatibility)
 */
int		handle_keyboard_input(int keycode, t_map *map);

/**
 * @brief Handle mouse movement for rotation
 * @param mouse_x X coordinate of mouse
 * @param mouse_y Y coordinate of mouse (unused)
 * @param map Pointer to the main game structure
 * @return 0 (for MLX compatibility)
 */
int		handle_mouse_rotation(int mouse_x, int mouse_y, t_map *map);

/* ========================================================================== */
/*                           PLAYER MOVEMENT                                 */
/* ========================================================================== */

/**
 * @brief Move player in specified direction with collision detection
 * @param map Pointer to the main game structure
 * @param delta_x X component of movement vector
 * @param delta_y Y component of movement vector
 * @param direction_sign '+' for forward/right, '-' for backward/left
 */
void	move_player_with_collision(t_map *map, double delta_x, double delta_y, char direction_sign);

/**
 * @brief Rotate player view direction
 * @param map Pointer to the main game structure
 * @param rotation_speed Speed and direction of rotation
 */
void	rotate_player_view(t_map *map, double rotation_speed);

/* ========================================================================== */
/*                            RAYCASTING ENGINE                              */
/* ========================================================================== */

/**
 * @brief Calculate delta distances for DDA algorithm
 * @param map Pointer to the main game structure
 */
void	calculate_delta_distances(t_map *map);

/**
 * @brief Calculate step direction and initial side distances
 * @param map Pointer to the main game structure
 */
void	calculate_step_and_side_distances(t_map *map);

/**
 * @brief Execute Digital Differential Analyzer (DDA) algorithm
 * @param map Pointer to the main game structure
 */
void	execute_dda_algorithm(t_map *map);

/**
 * @brief Initialize raycasting variables for current screen column
 * @param map Pointer to the main game structure
 * @param screen_x Current x coordinate on screen
 */
void	initialize_raycasting_for_column(t_map *map, int screen_x);

/**
 * @brief Main raycasting function - renders entire screen
 * @param map Pointer to the main game structure
 */
void	execute_raycasting(t_map *map);

/* ========================================================================== */
/*                            RENDERING UTILITIES                            */
/* ========================================================================== */

/**
 * @brief Get color from texture at specified coordinates
 * @param map Pointer to the main game structure
 * @param tex_x X coordinate in texture
 * @param tex_y Y coordinate in texture
 * @param texture_index Index of texture to sample from
 * @return Color value at specified texture coordinates
 */
int		get_texture_color(t_map *map, int tex_x, int tex_y, int texture_index);

/* ========================================================================== */
/*                              DRAWING FUNCTIONS                            */
/* ========================================================================== */

/**
 * @brief Put pixel to image buffer with bounds checking
 * @param map Pointer to the main game structure
 * @param x X coordinate
 * @param y Y coordinate
 * @param color Color value to set
 */
void	put_pixel_to_image(t_map *map, int x, int y, int color);

/**
 * @brief Draw a complete wall column on screen
 * @param map Pointer to the main game structure
 * @param screen_x X coordinate of column to draw
 */
void	draw_wall_column(t_map *map, int screen_x);

/**
 * @brief Calculate texture coordinates for wall rendering
 * @param map Pointer to the main game structure
 * @param line_start Start Y coordinate of wall line
 * @param line_height Height of wall line on screen
 */
void	calculate_texture_coordinates(t_map *map, int line_start, int line_height);

/**
 * @brief Main rendering function called every frame
 * @param map Pointer to the main game structure
 * @return 0 (for MLX loop compatibility)
 */
int		render_frame(t_map *map);

/* ========================================================================== */
/*                           BACKGROUND RENDERING                            */
/* ========================================================================== */

/**
 * @brief Create TRGB color value from individual components
 * @param transparency Transparency value
 * @param red Red component (0-255)
 * @param green Green component (0-255)
 * @param blue Blue component (0-255)
 * @return Combined TRGB color value
 */
int		create_trgb_color(int transparency, int red, int green, int blue);

/**
 * @brief Render floor and ceiling background
 * @param map Pointer to the main game structure
 */
void	render_background_colors(t_map *map);

/* ========================================================================== */
/*                              MINIMAP FUNCTIONS (BONUS)                   */
/* ========================================================================== */

#ifdef BONUS
/**
 * @brief Draw the complete minimap
 * @param map Pointer to the main game structure
 */
void	draw_minimap_display(t_map *map);

/**
 * @brief Update minimap when player moves
 * @param map Pointer to the main game structure
 * @param previous_x Previous X position
 * @param previous_y Previous Y position
 */
void	update_minimap_player_position(t_map *map, int previous_x, int previous_y);

/**
 * @brief Put pixel to minimap image with bounds checking
 * @param map Pointer to the main game structure
 * @param x X coordinate on minimap
 * @param y Y coordinate on minimap
 * @param color Color value to set
 */
void	put_pixel_to_minimap(t_map *map, int x, int y, int color);

/**
 * @brief Draw a single case/cell on the minimap
 * @param map Pointer to the main game structure
 * @param x X coordinate of case
 * @param y Y coordinate of case
 * @param color Color to fill the case
 */
void	draw_minimap_case(t_map *map, int x, int y, int color);
#endif

#endif