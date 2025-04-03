/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:46:01 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/06 20:12:28 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


char	**grid(int n){

	char	**array;
	array = (char **) malloc(sizeof(char *) * n);
	int i = 0;
	for (int i = 0; i < n; i++){
		array[i] = (char *) malloc(sizeof(char) * n);
		for (int j = 0; j < n; j++){
			array[i][j] = '*';
		}
	}
	return (array);
}

void	printGrid(char **array){
	int i = 0;

	while (array[i]){
		int j = 0;
		while (array[i][j]){
			printf("%c ", array[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int main(int argc, char **argv){
	char **array = grid(atoi(argv[1]));
	printGrid(array);
	return (0);
}