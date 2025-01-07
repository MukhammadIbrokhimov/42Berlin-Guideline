/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:39:45 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/07 21:10:09 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*readfile(fdf *map, char **file)
{
	int	fd;

	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	get_size(&map->height, fd, &map->width);
	close(fd);
	return (map);
}

int	get_size(int *height, int fd, int *width)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
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
	return (i);
}

