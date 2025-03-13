/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:41:20 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/13 19:40:55 by mukibrok         ###   ########.fr       */
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

void nqueens(char *str, int index, int end){
	if (index == end){
			printf("%s\n", str);
	}

	for (int i = index; i <= end; i++){
		swap(&str[index], &str[i]);
		
		char newarr[end + 1 + 1];
		for (int j = 0; str[j]; j++)
			newarr[j] = str[j];
		newarr[end + 1] = 0;
		buble(&newarr[index+1], strlen(&newarr[index+1]));

		nqueens(newarr, index + 1, end);
		swap(&str[index], &str[i]);
	}
}


int main(int argc, char **argv){
	if (argc != 2){
		return (1);
	}

	char *str = argv[1];
	int len = strlen(str);
	buble(str, len);
	nqueens(str, 0, len - 1);
	return (1);
}