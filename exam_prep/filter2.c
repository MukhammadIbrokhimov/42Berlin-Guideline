/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:58:38 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/04 17:14:13 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _GNU_SOURCE 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define buff_size 256

char *ft_getline(){
	int bytesread;
	char buff[buff_size];
	char *buffer;
	int size = 0;
	while (1){
		bytesread = read(0, buff, buff_size);
		if (bytesread == 0) break ;
		if (bytesread < 0) return (NULL);
		char *tmp = realloc(buffer, size + bytesread + 1);
		if (!tmp) return (free(buffer), NULL);
		buffer = tmp;
		int i = 0;
		while (i < bytesread){
			buffer[size + i] = buff[i];
			i++;
		}
		size += bytesread;
	}
	buffer[size] = '\0';
	return buffer;
}

int main(int argc, char **argv){
	if (argc != 2)
		return (1);
	char *find = argv[1];
	char *data = ft_getline();
	if (!data) return (1);
	char *current = memmem(data, strlen(data), find, strlen(find));
	while (current != NULL){
		for (int i = 0; i < strlen(find); i++){
			current[i] = '*';
		}
		current = memmem(data, strlen(data), find, strlen(find));
	}
	fprintf(stdout, "%s", data);
	free(data);
	return (0);
}