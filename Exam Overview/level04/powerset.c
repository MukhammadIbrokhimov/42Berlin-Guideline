/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:58:48 by mukibrok          #+#    #+#             */
/*   Updated: 2025/03/13 23:37:05 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_space(int c){
	return (c == 32);
}

int	ft_count(char *s){
	int word = 0;
	while (*s){
		while (is_space(*s) && *s)
			s++;
		if (!is_space(*s) && *s){
			word++;
			while(!is_space(*s) && *s){
				s++;
			}
		}
	}
	return (word);
}

int	*ft_atoi(char *str, int *size){
	*size = ft_count(str);
	int *n = malloc(sizeof(int) * (*size));
	if (!n) return (NULL);
	int i = 0;
	int j = 0;
	while (str[i]){
		while (is_space(str[i]))
			i++;
		if (!is_space(str[i])){
			n[j] = atoi(&str[i]);
			j++;
		}
		if (!is_space(str[i])){
			i++;
		}
	}
	return (n);
}

void	print_set(int *n, int size, int mask){
	int first = 1;

	printf("{");
	for (int i = 0; i < size; i++){
		if (mask & (1 << i)){
			if (!first) printf(", ");
			printf("%d", n[i]);
			first = 0;
		}
	}
	printf("}\n");
}

int main(int argc, char **argv){
	if  (argc != 3) return (1);
	int number_count;
	int *n = ft_atoi(argv[1], &number_count);
	//printf("%d\n", number_count);
	//for (int i = 0; i < number_count; i++){
	//	printf("%d ", n[i]);
	//}
	int target = atoi(argv[2]);
	//printf("\n");
	//int n[] = {1, 2, 3, 5};
	//int target = 5;

	//int size = sizeof(n) / sizeof(n[0]);
	int total_subset = 1 << number_count;
	for (int mask = 0; mask < total_subset; mask++){
		int sum = 0;
		for (int i = 0; i < number_count; i++){
			if (mask & (1 << i)) sum += n[i];
		}
		if (sum == target) print_set(n, number_count, mask);
	}
}



//void print_set(int *arr, int size, int mask) {
//	printf("{");
//	int first = 1;
//	for (int i = 0; i < size; i++) {
//		if (mask & (1 << i)) {
//			if (!first) printf(", ");
//			printf("%d", arr[i]);
//			first = 0;
//		}
//	}
//	printf("}\n");
//}

//int main(int argc, char **argv) {
//	//if (argc != 3)
//	//	return (1);
//	//int size;
//	int s[] = {6, 2, 5, 4}; // Example set
//	//int *s = ft_atoi((argv[1]), &size); // Example set
//	int n = 5; // Target sum
//	//int n = atoi(argv[2]); // Target sum
//	int size = 4;

//	int total_subsets = 1 << size; // 2^size subsets

//	//0000001 00000010 00000011 00000000,  00000000 
	
//	for (int mask = 0; mask < total_subsets; mask++) {
//		int sum = 0;
//		for (int i = 0; i < size; i++)
//			if (mask & (1 << i)) sum += s[i];

//		if (sum == n) print_set(s, size, mask);
//	}
	
//	return 0;
//}

//int main() {
//    int s[] = {1, 2, 3}; // Set elements
//    int size = sizeof(s) / sizeof(s[0]);

//    int total_subsets = 1 << size; // 2^size subsets
//    for (int mask = 0; mask < total_subsets; mask++) {
//        print_set(s, size, mask);
//    }

//    return 0;
//}

