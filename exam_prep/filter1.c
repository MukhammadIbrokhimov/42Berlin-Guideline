/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:01:09 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/05 20:14:20 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFERSIZE 1


void	printError(void){
	fprintf(stderr, "Error\n");
}

char *readtext(void){
	int bytesread;
	char buffer[BUFFERSIZE];
	char *tmp;
	char *data = NULL;
	size_t size = 0;
	while (1){
		bytesread = read(0, buffer, BUFFERSIZE);
		if (bytesread < 0) return (NULL);
		if (bytesread == 0) break;
		tmp = realloc(data, size + bytesread + 1);
		if (!tmp) return (printError(), free(data),  NULL);
		data = tmp;
		for (int i = 0; i < bytesread; i++){
			data[size + i] = buffer[i];
		}
		size += bytesread;
	}
	if (!data) return (NULL);
	data[size] = '\0';
	return (data);
	
}

int main(int argc, char **argv)
{
	if (argc != 2){
		return (1);
	}
	char *buffer = readtext();
	if (!buffer) return (printError(), 1);
	char *find = argv[1];
	int i = 0;
	char *current = current = memmem(buffer, strlen(buffer), find, strlen(find));
	while (current != NULL){
		for (int j = 0; j < strlen(find); j++){
			current[j] = '*';
		}
		current = memmem(buffer, strlen(buffer), find, strlen(find));
	}
	fprintf(stdout, "%s", buffer);
	free(buffer);
	return (0);
}
