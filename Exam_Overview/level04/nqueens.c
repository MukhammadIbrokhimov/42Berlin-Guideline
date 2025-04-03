/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:34:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/13 19:51:02 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:41:20 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/13 19:21:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void swap(char *a, char *b){
	char tmp = *a;
	*a = *b; 
	*b = tmp;
}

void buble(char *str, int len)
{
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - i - 1; j++){
			if (str[j] > str[j + 1]){
				swap(&str[j], &str[j + 1]);
			}
		}
	}
}

int checker(char*str)
{
	//023
}


void nqueens(int *arr, int index, int num_queens){
	if (index == num_queens - 1){
		if //checker_valid)
			for (int i = 0; i < num_queens; i++)
			printf("%i", arr[i]);
	}

	//checker up to index invalid
	//return;

	for (int i = index; i <= num_queens; i++){
		swap(&str[index], &str[i]);
		nqueens(newarr, index + 1, num_queens);
		swap(&str[index], &str[i]);
	}
}


int main(int argc, char **argv){
	if (argc != 2){
		return (1);
	}

	int numqueens = atoi(argv[1]);
	int i = 0;
	int *arr;
	//initialize the array
	while(i < numqueens)
		arr[i] = i;
	char *str = argv[1];
	int len = strlen(str);
	buble(str, len);
	nqueens(str, 0, len - 1);
	return (1);
}