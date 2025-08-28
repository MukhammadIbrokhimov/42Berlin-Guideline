/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:30:20 by gansari           #+#    #+#             */
/*   Updated: 2025/08/22 12:56:40 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (!validate_arguments(argc, argv))
		return (1);
	if (!validate_input_file(argv[1]))
		return (2);
	fd = open(argv[1], O_RDONLY);
	if (!is_valid_file_descriptor(fd))
		return (3);
	init_game_structure(&game);
	if (!is_parseable_map_file(&game, fd))
		return (4);
	close(fd);
	if (init_game_engine(&game) != 0)
	{
		printf("Error\nGame engine initialization failed\n");
		free_string_array(game.map.grid);
		return (5);
	}
	return (0);
}
