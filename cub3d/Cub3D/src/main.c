/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:41:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/13 01:54:19 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cub3D.h"

/**
 * Main function - Entry point of the program
 * 1. Validate command line arguments
 * 2. Initialize game structure
 * 3. Parse the .cub file
 * 4. Validate the parsed data
 * 5. Clean up and exit
 */

int	main(int argc, char **argv)
{
	t_game	map;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <map_file>\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (validate_file_extension(argv[1]) == false) // completed
	{
		ft_putstr_fd("Error: Invalid map file.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	init_map(&map); // completed
	parse_file(&map, argv[1]);
	if (!validate_map(&map)) // not ready
	{
		cleanup_map(&map); // not ready
		return(EXIT_FAILURE);
	}
	print_map(&map); // For debugging, remove in production
	cleanup_map(&map);
	return (EXIT_SUCCESS);
}

