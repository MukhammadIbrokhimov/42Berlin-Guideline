/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:41:13 by gansari           #+#    #+#             */
/*   Updated: 2024/12/05 14:26:39 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_next_line(char *str, int line_init)
{
	char	*new_str;
	int		len;

	len = ft_strlen(str) - line_init;
	if (len <= 0)
	{
		free(str);
		return (NULL);
	}
	new_str = ft_substr(str, line_init, len);
	free(str);
	return (new_str);
}

static char	*find_line(char *str, int *line_init)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		*line_init = i + 1;
	else
	{
		*line_init = i;
		if (i == 0 && str[i] == '\0')
			return (NULL);
	}
	line = ft_substr(str, 0, *line_init);
	return (line);
}

static char	*read_str(int fd, char *buffer, char *str)
{
	int		read_bytes;
	char	*temp;

	while (!ft_strchr(str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0 && str[0] == '\0')
		{
			free(str);
			return (NULL);
		}
		if (read_bytes <= 0)
			return (str);
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		str = temp;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*str[FOPEN_MAX];
	int			line_init;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str[fd] = read_str(fd, buffer, str[fd]);
	free(buffer);
	if (!str[fd])
		return (NULL);
	line = find_line(str[fd], &line_init);
	if (!line && !str[fd])
		return (NULL);
	str[fd] = find_next_line(str[fd], line_init);
	return (line);
}
