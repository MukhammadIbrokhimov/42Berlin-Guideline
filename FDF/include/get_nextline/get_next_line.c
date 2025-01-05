/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:42:14 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/02 16:46:04 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *stack)
{
	int		bytesread;
	char	*buf;
	char	*tmp;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(stack), stack = NULL, NULL);
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(buf), free(stack), stack = NULL, NULL);
		if (bytesread == 0)
			break ;
		buf[bytesread] = '\0';
		if (!stack)
			stack = ft_strdup("");
		tmp = stack;
		stack = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(buf), stack);
}

int	till_nextline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*extract_line(char *stack)
{
	size_t	len;
	char	*str;

	if (!stack || stack[0] == '\0')
		return (NULL);
	len = till_nextline(stack);
	if (stack[len] == '\n')
		len += 1;
	str = ft_substr(stack, 0, len);
	if (!str)
		return (NULL);
	return (str);
}

char	*stack_update(char *stack)
{
	char	*new_stack;
	size_t	len;
	size_t	stack_len;

	len = till_nextline(stack);
	if (!stack[len])
		return (free(stack), stack = NULL, NULL);
	stack_len = ft_strlen(stack);
	if (stack[len] == '\n')
		len += 1;
	new_stack = ft_substr(stack, len, stack_len - len);
	if (!new_stack)
		return (free(stack), stack = NULL, NULL);
	free(stack);
	return (new_stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stack = read_file(fd, stack);
	if (!stack)
		return (NULL);
	line = extract_line(stack);
	if (!line)
		return (free(stack), stack = NULL, NULL);
	stack = stack_update(stack);
	return (line);
}
