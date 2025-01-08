/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:57:46 by mukibrok          #+#    #+#             */
/*   Updated: 2025/01/08 13:06:58 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_nextline/get_next_line.h"

typedef		struct
{
	int		height;
	int		width;
	int		**render_map;
}			fdf;

// file rendering functions
fdf	*readfile(fdf	*map, char **file);
int	get_size(int *height, char *file, int *width);
int	**allocate(int height, int width, char **file);
int	*fill_map(int *map_line, int width, char *line);
// helper functions
void	free_arr(char **str);
void	free_map(int **arr);
void	ft_print(int **map, int height, int width);

#endif
