/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:51:23 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/21 14:00:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d.h"

int	count_elems(char **v)
{
	int	i;

	i = 0;
	while (v && v[i])
		i++;
	return (i);
}

void	strip_trailing_nl(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

int	is_number(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	extract_texture(t_game *game, char **tex_path, char **split_line)
{
	int	n;

	n = count_elems(split_line);
	if (n >= 1)
		strip_trailing_nl(split_line[n - 1]);
	if (n != 2 || *tex_path != NULL)
	{
		free_string_array(split_line);
		handle_parsing_error(game,
			"Error\nInvalid or duplicate texture definition\n");
	}
	*tex_path = ft_strdup(split_line[1]);
	if (!*tex_path)
	{
		free_string_array(split_line);
		handle_parsing_error(game,
			"Error\nMemory allocation failed for texture path\n");
	}
	strip_trailing_nl(*tex_path);
	free_string_array(split_line);
}

int	validate_rgb_line_format(char *rgb_line)
{
	int	i;
	int	commas;

	if (!rgb_line)
		return (0);
	strip_trailing_nl(rgb_line);
	if (!ft_isdigit((unsigned char)rgb_line[0]))
		return (0);
	i = 0;
	commas = 0;
	while (rgb_line[i])
	{
		if (rgb_line[i] == ',')
		{
			commas++;
			if (rgb_line[i + 1] == ',' || rgb_line[i + 1] == '\0')
				return (0);
		}
		else if (!ft_isdigit((unsigned char)rgb_line[i]))
			return (0);
		i++;
	}
	return (commas == 2);
}
