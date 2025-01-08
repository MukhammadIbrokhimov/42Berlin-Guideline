/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:37:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/08 13:25:27 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int argc, char **argv)
{
	fdf	*map;

	map = NULL;
	if (argc != 2)
		return (ft_printf("./fdf [map]\n"), 0);
	map = (fdf *) malloc(sizeof(fdf));
	if (!map) return (-1);
	map = readfile(map, argv);
	free_map(map->render_map);
	free(map);
	return (0);
}