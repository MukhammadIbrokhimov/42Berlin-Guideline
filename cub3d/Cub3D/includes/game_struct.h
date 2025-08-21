/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:54:13 by gansari           #+#    #+#             */
/*   Updated: 2025/08/11 21:17:49 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCT_H
# define GAME_STRUCT_H

/**
 * @brief Image structure for MLX image handling
 * 
 * This structure contains all necessary information for managing
 * MLX images including textures and the main display buffer.
 */
typedef struct s_image_data
{
	void	*mlx_image_ptr;		/* MLX image pointer */
	char	*texture_path;		/* Path to texture file (for wall textures) */
	char	*image_buffer;		/* Direct access to image pixel data */
	int		bits_per_pixel;		/* Number of bits per pixel */
	int		line_length;		/* Length of one line in bytes */
	int		endianness;			/* Endianness of the image data */
	int		image_width;		/* Width of the image in pixels */
	int		image_height;		/* Height of the image in pixels */
}	t_image_data;

/**
 * @brief Main game structure containing all game state
 * 
 * This structure holds all the data needed for the raycasting engine,
 * including MLX pointers, map data, player state, and rendering information.
 */
typedef struct s_game_map
{
	/* ============================== MLX DATA =============================== */
	void			*mlx_instance;		/* MLX instance pointer */
	void			*mlx_window;		/* MLX window pointer */
	t_image_data	texture_images[5];	/* Array of texture images [N,S,W,E,Display] */
	
	#ifdef BONUS
	t_image_data	minimap_image;		/* Minimap image data (bonus feature) */
	#endif
	
	/* ========================== DISPLAY SETTINGS =========================== */
	int				display_width;		/* Window width in pixels */
	int				display_height;		/* Window height in pixels */
	
	/* ============================= MAP DATA ============================== */
	char			**map_grid;			/* 2D array representing the game map */
	int				map_width;			/* Width of the map in grid units */
	int				map_height;			/* Height of the map in grid units */
	
	/* ========================== PLAYER STATE ============================ */
	char			player_direction;	/* Initial player direction (N/S/E/W) */
	double			player_pos_x;		/* Current player X position */
	double			player_pos_y;		/* Current player Y position */
	double			player_dir_x;		/* Player direction vector X component */
	double			player_dir_y;		/* Player direction vector Y component */
	double			camera_plane_x;		/* Camera plane X component (FOV) */
	double			camera_plane_y;		/* Camera plane Y component (FOV) */
	
	/* ========================== COLOR SETTINGS =========================== */
	int				floor_color_rgb[3];	/* Floor color RGB values [R,G,B] */
	int				ceiling_color_rgb[3];/* Ceiling color RGB values [R,G,B] */
	
	/* ========================= PARSING BUFFERS ========================== */
	char			*current_line;		/* Current line being parsed */
	char			*map_data_buffer;	/* Buffer for accumulating map data */
	
	/* ======================== TEXTURE RENDERING ========================= */
	double			wall_hit_x;			/* X coordinate where ray hits wall */
	int				texture_x;			/* X coordinate in texture */
	int				texture_y;			/* Y coordinate in texture */
	double			texture_step;		/* Step size for texture sampling */
	double			texture_position;	/* Current position in texture */
	
	/* ========================= RAYCASTING DATA ========================== */
	double			ray_direction_x;	/* Current ray direction X component */
	double			ray_direction_y;	/* Current ray direction Y component */
	double			camera_x;			/* X coordinate on camera plane (-1 to 1) */
	double			side_distance_x;	/* Distance to next X map square */
	double			side_distance_y;	/* Distance to next Y map square */
	double			delta_distance_x;	/* Distance between X map squares */
	double			delta_distance_y;	/* Distance between Y map squares */
	double			perpendicular_wall_distance;	/* Perpendicular distance to wall */
	
	/* ========================= MAP TRAVERSAL ============================ */
	int				current_map_x;		/* Current X position in map grid */
	int				current_map_y;		/* Current Y position in map grid */
	int				step_x;				/* Step direction in X (-1 or 1) */
	int				step_y;				/* Step direction in Y (-1 or 1) */
	int				wall_side;			/* Which side of wall was hit (0=X, 1=Y) */
	
	/* ========================= WALL RENDERING =========================== */
	int				wall_distance;		/* Distance to wall (for shading) */
	int				line_height;		/* Height of wall line on screen */
	int				line_start_y;		/* Y coordinate where wall starts */
	int				line_end_y;			/* Y coordinate where wall ends */
	int				draw_start;			/* Start Y coordinate for drawing */
	int				draw_end;			/* End Y coordinate for drawing */
	
	/* ======================== MOVEMENT SETTINGS ========================= */
	double			movement_speed;		/* Player movement speed */
	double			rotation_speed;		/* Player rotation speed */

}	t_game_map;

/* Legacy typedef for backward compatibility */
typedef t_game_map t_map;

/* ************************************************************************** */
/*                           STRUCTURE DOCUMENTATION                         */
/* ************************************************************************** */

/*
 * STRUCTURE USAGE NOTES:
 * 
 * t_image_data:
 * - Used for both wall textures and the main display buffer
 * - texture_path is only used for wall textures (indices 0-3)
 * - Index 4 in texture_images array is the main display buffer
 * - mlx_image_ptr must be freed with mlx_destroy_image()
 * - texture_path must be freed with free() if allocated
 * 
 * t_game_map:
 * - Central structure containing all game state
 * - map_grid is a 2D array where '1' = wall, '0' = empty space
 * - Player position is stored as floating point for smooth movement
 * - Direction vectors are normalized for consistent movement speed
 * - Camera plane determines the field of view (typically 0.66 for 90°)
 * - Color arrays store RGB values in range [0-255]
 * - Raycasting variables are recalculated for each screen column
 * - Movement and rotation speeds should be frame-rate independent
 * 
 * COORDINATE SYSTEM:
 * - X axis: Left to right (West to East)
 * - Y axis: Top to bottom (North to South)
 * - Map coordinates: Integer grid positions
 * - Player coordinates: Floating point positions within grid
 * - Screen coordinates: Pixel positions on display
 * 
 * MEMORY MANAGEMENT:
 * - All pointers in structures must be properly freed
 * - map_grid is allocated as array of strings
 * - MLX resources must be freed in correct order
 * - Always check for NULL pointers before freeing
 */

#endif