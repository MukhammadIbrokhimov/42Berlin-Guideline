/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:30:20 by gansari           #+#    #+#             */
/*   Updated: 2025/08/30 19:22:58 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_mandatory/cub3d.h"

int	parse_map_file(t_game *game, int file_descriptor)
{
	if (!read_and_parse_map_file(file_descriptor, game))
		return (0);
	normalize_map_dimensions(game);
	if (!validate_parsed_map(game))
		return (0);
	close(file_descriptor);
	return (1);
}

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
