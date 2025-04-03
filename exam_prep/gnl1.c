/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:16:17 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/05 17:21:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define buffersize 256

char *ft_strjoin(char *dst, char *src){
	if (!dst || !src) return (NULL);
	int size_dst = strlen(dst);
	int size_src = strlen(src);
	char *stack = malloc(size_dst + size_src + 1);
	if (!stack) return (NULL);
	int i = 0;
	while (dst[i]){
		stack[i] = dst[i];
		i++;
	}
	int j = 0;
	while (src[j]){
		stack[i + j] = src[j];
		j++;
	}
	stack[i + j] = '\0';
	return stack;
}

char *ft_getline(int fd, char *buffer){
	int bytesread;
	char buf[buffersize];
	while (1){
		bytesread = read(fd, buf, buffersize);
		if (bytesread == 0) break ;
		if (bytesread < 0) return (NULL);
		buf[bytesread] = '\0';
		//printf("bytesread: %d\n", bytesread);
		//printf("+++++++++++++++++++++++++++++++++++++++\n");
		if (!buffer){
			buffer = strdup("");
			if (!buffer) return (NULL);
		}
		char *tmp = buffer;
		buffer = ft_strjoin(tmp, buf);
		if (!buffer) {
			free(tmp);
			return (NULL);
		}
		free(tmp);		
		if (strchr(buf, '\n')){
			break ;
		}
	}
	return (buffer);
}

int tillNextLine(char *src){
	int i = 0;
	while (src[i] != '\0' && src[i] != '\n'){
		i++;
	}
	if (src[i] == '\n')
		i++;
	return (i);
}

char *ft_substr(char *str, int start, int end){
	int str_len = end - start;
	if (str_len == 0) return (NULL);
	char *line = malloc(str_len + 1);
	if (!line) return (NULL);
	int i = 0;
	while (i < str_len){ // probably should not be - 1
		line[i] = str[start + i];
		i++;
	}
	line[str_len] = '\0';
	return (line);
}

char *extract_line(char *stack){
	int tillLine = tillNextLine(stack);
	if (tillLine == 0)	return (NULL);
	char *line = ft_substr(stack, 0, tillLine);
	if (!line) return (NULL);
	return (line);
}

char *update_stack(char *stack){
	if (!stack) return (NULL);
	int tillLine = tillNextLine(stack);
	int stackLen = strlen(stack);
	int newLen = stackLen - tillLine;
	if (newLen <= 0) return (free(stack), NULL);
	char *newStack = ft_substr(stack, tillLine, stackLen);
	if (!newStack) return (free(stack), NULL);
	free(stack);
	return (newStack);
}

char *getnext_line(int fd){
	static char *stack;
	char *line = NULL;
	if (fd <= 0 || buffersize <= 0) return NULL;
	//printf("before calling ft_getline\n");
	//printf("+++++++++++++++++++++++++++++++++++++++\n");
	stack = ft_getline(fd, stack);
	//printf("after get line function: %s\n", stack);
	//printf("+++++++++++++++++++++++++++++++++++++++\n");
	if (!stack) return (NULL);
	line = extract_line(stack);
	if (!line) return (free(stack), stack = NULL, NULL);
	stack = update_stack(stack);
	if (!stack) return (free(line), NULL);
	return (line);
}

int main(void){
	char *str;
	int fd = open("text.txt", O_RDONLY);
	//printf("fd: %d\n", fd);
	int i = 0;
	while ((str = getnext_line(fd)) != NULL){
		printf("%s", str);
		free(str);
		if (i == 5){
			close(fd);
			str = getnext_line(fd);
		}
		i++;
	}
	free(str);
}