/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:22:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/27 16:17:41 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BYTESSIZE 20

	char *ft_strjoin(char *s, char *s1){
		if (!s || !s1) return (NULL);
		char *str = malloc(strlen(s) + strlen(s1) + 1);
		if (!str) return (NULL);
		strcpy(str, s);
		strcat(str, s1);
		return (str);
	}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	substring = NULL;
	if (!s)
		return (NULL);
	if (strlen(s) <= start)
		return (strdup(""));
	if (len > strlen(s) - start)
		len = strlen(s) - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char *ft_readline(int fd, char *stack){
	int	bytesread;
	char *buffer = calloc(BYTESSIZE, sizeof(char));
	while (!strchr(buffer, '\n')){
		bytesread = read(fd, buffer, BYTESSIZE);
		if (bytesread < 0) return (free(stack), free(buffer), NULL);
		if (bytesread == 0) break ;
		if (!stack){
			stack = strdup("");
		}
		buffer[BYTESSIZE] = '\0';
		char *tmp = stack;
		stack = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!stack) return (free(buffer), NULL);
	}
	return (free(buffer), buffer = NULL, stack);
}

int	tillNewLine(char *s){
	int i;

	i = 0;
	if (!s) return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (i);
	//printf("DEBUG: <tillNextLine> : %d\n", i);
	return (i + 1);
}

char *extract_line(char *stack){
	if (!stack) return NULL;
	int linelength = tillNewLine(stack);
	char *s = ft_substr(stack, 0, linelength);
	if (!s) return (free(stack), NULL);
	return (s);
}

char *updateStack(char *stack){
	int new_start = tillNewLine(stack);

	if (!stack || new_start >= (int)strlen(stack)) {
		free(stack);
		return (NULL);
	}
	char *update_stack = ft_substr(stack, new_start, strlen(stack) - new_start);
	free(stack);
	return (update_stack);
}


char *getnext_line(int fd) {
	static char *stack;
	if (fd < 0 || BYTESSIZE == 0) return NULL;

	stack = ft_readline(fd, stack);
	if (!stack) return NULL;

	char *line = extract_line(stack);
	char *new_stack = updateStack(stack);

	if (!new_stack) {
		free(stack); // Ensure we free the old stack
	}

	stack = new_stack;
	return line;
}

int main(int argc, char **argv){
	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	char *str;
	int i = 0;
	str = getnext_line(fd);
	while (str){
		printf("%s", str);
		free(str);
		str = getnext_line(fd);
	}
	free(str);
	close(fd);
	return (0);
}