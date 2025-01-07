/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:39:45 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/07 20:31:20 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*readfile(fdf *map, char **file)
{
	int	height;
	int	width;
	int	fd;

	fd = open(file[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	ft_printf("file descriptor: %d\n", fd);
	height = get_size(&map->height, fd, &width);
	ft_printf("height descriptor: %d\n", height);
	//width = get_width(&map->width, file);
	ft_printf("width descriptor: %d\n", width);
	map->render_map = allocate(height, width, file);
	ft_print(map->render_map, height, width);
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

void	fill_map(int **map, char **file, int *i)
{
	char	**numbers;
	int		fd;
	int		j;

	fd = open(file[1], O_RDONLY);
	if (!fd || !map)
		return ;
	numbers = ft_split(get_next_line(fd), ' ');
	j = 0;
	while (numbers[j])
	{
		map[*i][j] = ft_atoi(numbers[j]);
		j++;
	}
	free_arr(numbers);
}

int	**allocate(int height, int width, char **file)
{
	int		**arr;
	int		i;

	i = 0;
	arr = NULL;
	if (!height || !width)
		return (arr);
	arr = (int **) malloc(sizeof(int *) * height);
	if (!arr)
		return (NULL);
	while (i < height)
	{
		arr[i] = (int *) malloc(sizeof(int) * width);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		fill_map(arr, file, &i);
		i++;
	}
	return (arr);
}

