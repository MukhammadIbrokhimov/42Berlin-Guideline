/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:02:03 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/13 17:36:39 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(char *str, int len){
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - i - 1; j++){
			if (str[j] > str[j + 1]){
				swap(&str[j], &str[j + 1]);
			}
		}
	}
}

void	permutations(char *str, int start, int end){
	if (start == end){
		printf("%s\n", str);
	}
	for (int i = start; i <= end; i++){
		swap(&str[start], &str[i]);
		permutations(str, start + 1, end);
		swap(&str[start], &str[i]);
	}
}

int main(int argc, char **argv){
	if (argc != 2) return 1;
	char *str = argv[1];
	int len = strlen(str);
	bubble_sort(str, len);
	permutations(str, 0, len - 1);
	return (1);
}