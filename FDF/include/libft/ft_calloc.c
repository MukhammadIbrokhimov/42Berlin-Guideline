/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:35:23 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/16 11:10:42 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t amount, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	arr = malloc(size * amount);
	if (!arr)
		return (NULL);
	while (i < size * amount)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

// int main() {
//     // Test 1: Allocate memory for an array of 5 integers
//     int *ft_result = (int *)ft_calloc(5, sizeof(int));
//     int *std_result = (int *)calloc(5, sizeof(int));

//     printf("Test 1: Allocating memory for 5 integers )\n");

//     // Compare both results
//     if (ft_result && std_result) {
//         if (memcmp(ft_result, std_result, 5 * sizeof(int)) == 0) {
//             printf("ft_calloc and calloc results match: PASS\n");
//         } else {
//             printf("ft_calloc and calloc results do not match: FAIL\n");
//         }
//     } else {
//         printf("Memory allocation failed\n");
//     }

//     // Free the allocated memory
//     free(ft_result);
//     free(std_result);

//     // Test 2: Allocate memory for 0 elements (edge case)
//     ft_result = (int *)ft_calloc(0, sizeof(int));
//     std_result = (int *)calloc(0, sizeof(int));

//     printf("Test 2: Allocating memory for 0 elements\n");

//     if (ft_result == std_result) {
//         printf("ft_calloc and calloc results match (both NULL): PASS\n");
//     } else {
//         printf("ft_calloc and calloc results do not match: FAIL\n");
//     }

//     // Test 3: Allocate a large amount of memory
//     ft_result = (int *)ft_calloc(10000, sizeof(int));
//     std_result = (int *)calloc(10000, sizeof(int));

//     printf("Test 3: Allocating memory for 10000 integers\n");

//     if (ft_result && std_result) {
//         if (memcmp(ft_result, std_result, 10000 * sizeof(int)) == 0) {
//             printf("ft_calloc and calloc results match: PASS\n");
//         } else {
//             printf("ft_calloc and calloc results do not match: FAIL\n");
//         }
//     } else {
//         printf("Memory allocation failed\n");
//     }

//     // Free the allocated memory
//     free(ft_result);
//     free(std_result);

//     return 0;
// }
