/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:39:45 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/08 13:27:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*readfile(fdf *map, char **file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	get_size(&map->height, file[1], &map->width);
	map->render_map = (int **) malloc(sizeof(int *) * (map->height + 1));
	while (i < map->height)
		map->render_map[i++] = (int *) malloc(sizeof(int) * map->width);
	i = 0;
	line = get_next_line(fd);
	while (i < map->height && line)
	{
		fill_map(map->render_map[i++], map->width, line);
		line = get_next_line(fd);
	}
	map->render_map[map->height] = NULL;
	ft_print(map->render_map, map->height, map->width);
	close(fd);
	return (map);
}

int *fill_map(int *map_line, int width, char *line)
{
	int i;
	char **number;

	i = 0;
	number = ft_split(line, ' ');
	while (i < width)
	{
		map_line[i] = ft_atoi(number[i]);
		i++;
	}
	free_arr(number);
	return map_line;
}

int	get_size(int *height, char *file, int *width)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line = get_next_line(fd);
	*width = count_words(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i += 1;
	}
	free(line);
	*height = i;
	close(fd);
	return (i);
}

