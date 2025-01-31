/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:39:45 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/31 20:10:39 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*readfile(fdf *data, char **file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (free(data), NULL);
	if (get_size(&data->map.height, file[1], &data->map.width) == 1)
		return (free(data), NULL);
	data->map.render_map = malloc(sizeof(int *) * (data->map.height + 1));
	while (i < data->map.height)
		data->map.render_map[i++] = malloc(sizeof(int) * data->map.width);
	i = 0;
	line = get_next_line(fd);
	while (i < data->map.height && line)
	{
		fill_map(data->map.render_map[i++], data->map.width, line);
		line = get_next_line(fd);
	}
	data->map.render_map[data->map.height] = NULL;
	close(fd);
	return (data);
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

int	*fill_map(int *map_line, int width, char *line)
{
	int		i;
	char	**number;

	i = 0;
	number = ft_split(line, ' ');
	while (i < width)
	{
		map_line[i] = ft_atoi(number[i]);
		i++;
	}
	free_arr(number);
	return (map_line);
}
