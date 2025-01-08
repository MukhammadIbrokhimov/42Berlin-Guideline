/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperFunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:59:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/08 18:46:19 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

fdf	*ft_lst(void)
{
	fdf	*map;

	map = NULL;
	map = (fdf *) malloc(sizeof(fdf));
	if (!map)
		return (NULL);
	map->zoom = 30;
	return (map);
}

void	free_arr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_map(int **arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void ft_print(int **map, int height, int width)
{
	int i, j;

	i = 0;
	if (!map)
		return;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}

}
