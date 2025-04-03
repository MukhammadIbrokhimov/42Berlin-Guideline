/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:13:47 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/26 19:46:51 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFERSIZE 1

void	printError(char *str){
	while (*str){
		write(2, str++, 1);
	}
}

char *ft_getline(){
	int bytesRead;
	int size = 0;
	char buffer[BUFFERSIZE];
	char *bufferr = NULL;
	while (bytesRead = (read(STDIN_FILENO, buffer, BUFFERSIZE)) > 0){
		if (bytesRead == 0) break;
		if (bytesRead < 0){
			return (printError("Error\n"), NULL);
		}
		char *new_buffer = realloc(bufferr, size + bytesRead + 1);
		if (!new_buffer) return (printError("Error\n"), free(bufferr), NULL);

		bufferr = new_buffer;
		for (int i = 0; i < bytesRead; i++){
			bufferr[size + i] = buffer[i];
		}
		size += bytesRead;
	}
	if (size == 0)	return (printError("Error\n"), NULL);
	bufferr[size] = '\0';
	return (bufferr);
}

int main(int argc, char **argv){
	if (argc != 2){
		return (printError("Error\n"), -1);
	}
	char *s = argv[1];
	size_t len = strlen(s);
	char *buffer = ft_getline();
	int i = 0;
	char *current;
	while (buffer[i]){
		if (strncmp(&buffer[i], s, len) == 0){
			for (int j = 0; j < len; j++){
				write(1, "*", 1);
			}
			i += len;
		}
		else{
			write(1, &buffer[i], 1);
			i++;
		}
	}
	free(buffer);
	return (0);
}

		//int i = 0;
		//while (i < bytesRead){
		//	char *current_pos;
		//	if (current_pos = memmem(buffer, strlen(buffer), s, strlen(s)) != NULL){
		//		for (size_t j = 0; j < len; j++){
		//			write(1, "*", 1);
		//		}
		//		i += len;
		//	}
		//	else{
		//		write(1, &buffer[i++], 1);
		//	}
		//}
