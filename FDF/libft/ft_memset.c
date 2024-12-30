/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:10:30 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/08 17:02:51 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	value;

	ptr = s;
	value = (unsigned char) c;
	while (n--)
		*ptr++ = value;
	return (s);
}

// int main(void)
// {
// 	int arr[] = {1, 4, 6, 5, 3, 2, 6, 7};
// 	// char	arr1[] = "school";
// 	int c = 0;
// 	char c = 'a';
// 	//ft_memset(arr, c, 8);
// 	// memset(arr, c, 8);
// 	ft_memset(arr1, c, ft_strlen(arr1));
// 	printf("%s\n", arr1);
// 	// for(int i = 0; i< 8; i++)
// 	// {
// 	// 	printf("%d->", arr[i]);
// 	// }
// }
