/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:57:19 by gansari           #+#    #+#             */
/*   Updated: 2025/05/16 11:21:42 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	const char *s = "hello world";
// 	const char *reject = "wpqr";
// 	size_t my_result = ft_strcspn(s, reject);
// 	size_t std_result = strcspn(s, reject);
// 	printf("My Result: %zu\n", my_result); // Expected output: 1
// 	printf("Standard Result: %zu\n", std_result); // Expected output: 1
// 	return 0;
// }
