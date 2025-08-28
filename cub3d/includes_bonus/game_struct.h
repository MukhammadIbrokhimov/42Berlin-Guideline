/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:54:13 by gansari           #+#    #+#             */
/*   Updated: 2025/08/26 19:02:55 by mukibrok         ###   ########.fr       */
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
typedef struct s_image
{
	void	*mlx_ptr;
	char	*path;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

/**
 * @brief MLX-related data and window management
 */

typedef struct s_mlx
{
	void	*instance;
	void	*window;
	int		width;
	int		height;
}	t_mlx;

/**
 * @brief Map configuration and data
 */
typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	char		*current_line;
	char		*data_buffer;
}	t_map;

/**
 * @brief Player position, direction and movement
 */

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		initial_dir;
	double		move_speed;
	double		rotate_speed;
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_left;
	int			key_right;
}	t_player;

/**
 * @brief Raycasting calculation data
 */
typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		camera_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
}	t_ray;

/**
 * @brief Wall rendering and texture data
 */

typedef struct s_wall
{
	double		hit_x;
	int			tex_x;
	int			tex_y;
	double		tex_step;
	double		tex_pos;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_wall;

/**
 * @brief Texture management system
 */
typedef struct s_textures
{
	t_image		north;
	t_image		south;
	t_image		east;
	t_image		west;
	t_image		screen;
	t_image		minimap;
}	t_textures;

/**
 * @brief Main game structure - orchestrates all subsystems
 */

typedef struct s_game
{
	t_mlx			mlx;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_wall			wall;
	t_textures		textures;
}	t_game;

/* ************************************************************************** */
/*                           STRUCTURE DOCUMENTATION                         */
/* ************************************************************************** */

/*
 * REFACTORED STRUCTURE BENEFITS:
 * 
 * 1. SEPARATION OF CONCERNS:
 *    - Each struct handles a specific aspect of the game
 *    - Easier to understand and maintain individual components
 *    - Clear relationships between different systems
 * 
 * 2. IMPROVED READABILITY:
 *    - Shorter, more descriptive member names
 *    - Logical grouping of related data
 *    - Self-documenting structure organization
 * 
 * 3. EASIER DEBUGGING:
 *    - Can examine specific subsystems independently
 *    - Clear data flow between components
 *    - Reduced complexity per structure
 * 
 * 4. BETTER MAINTAINABILITY:
 *    - Changes to one subsystem don't affect others
 *    - Easy to add new features to specific areas
 *    - Clear interface boundaries
 * 
 * USAGE PATTERNS:
 * 
 * - Access MLX data: game->mlx.instance, game->mlx.window
 * - Access map data: game->map.grid, game->map.width
 * - Access player: game->player.pos_x, game->player.dir_x
 * - Access textures: game->textures.north.mlx_ptr
 * - Access raycasting: game->ray.dir_x, game->ray.side_dist_x
 * 
 * MEMORY MANAGEMENT:
 * - Each subsystem can have its own cleanup function
 * - Clear ownership of pointers and resources
 * - Easier to track memory allocation/deallocation
 */

#endif