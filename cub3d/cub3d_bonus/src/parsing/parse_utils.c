/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:53:18 by mukibrok          #+#    #+#             */
/*   Updated: 2025/08/21 14:02:06 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Check if a character is present in a list of valid characters
 */

int	is_character_valid(char character, char *valid_characters)
{
	int	index;

	index = 0;
	while (valid_characters[index])
	{
		if (character == valid_characters[index])
			return (1);
		index++;
	}
	return (0);
}

/**
 * @brief Calculate string length excluding newline character
 */

int	get_string_length_no_newline(char *string)
{
	int	length;

	length = 0;
	while (string && string[length] && string[length] != '\n')
		length++;
	return (length);
}

/**
 * @brief Resize a string to a specific length, padding with spaces
 */

char	*resize(char *org_str, int target_size)
{
	int		copy_index;
	char	*resized_string;

	copy_index = 0;
	resized_string = malloc(sizeof(char) * (target_size + 1));
	if (!resized_string)
		return (NULL);
	while (org_str && org_str[copy_index] && copy_index < target_size)
	{
		resized_string[copy_index] = org_str[copy_index];
		copy_index++;
	}
	while (copy_index < target_size)
	{
		resized_string[copy_index] = ' ';
		copy_index++;
	}
	resized_string[target_size] = '\0';
	if (org_str)
		free(org_str);
	return (resized_string);
}

/**
 * @brief Join two strings with a forward slash separator
 */

char	*join_strings(char *first_string, char *second_string)
{
	int		total_length;
	int		copy_index;
	char	*joined_string;

	copy_index = 0;
	total_length = get_string_length_no_newline(first_string) + 
		get_string_length_no_newline(second_string);
	joined_string = malloc(sizeof(char) * (total_length + 2));
	if (!joined_string)
		return (NULL);
	while (first_string && first_string[copy_index])
	{
		joined_string[copy_index] = first_string[copy_index];
		copy_index++;
	}
	while (*second_string && *second_string != '\n')
	{
		joined_string[copy_index] = *second_string;
		copy_index++;
		second_string++;
	}
	joined_string[total_length] = '/';
	if (first_string)
		free(first_string);
	return (joined_string[total_length + 1] = '\0', joined_string);
}
