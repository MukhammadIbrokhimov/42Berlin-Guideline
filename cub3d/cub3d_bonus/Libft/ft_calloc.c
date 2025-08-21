/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:47:07 by gansari           #+#    #+#             */
/*   Updated: 2024/11/14 13:27:26 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size > INT_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	size_t	num_elements = 10;
	size_t	element_size =  sizeof(int);
	size_t	i;
	int	*arr1 = (int *)ft_calloc(num_elements, element_size);

	i = 0;
	while (i < num_elements)
	{
		if (arr1[i] != 0)
		{
			printf("Test failed: arr[%zu] is not zero.\n", i);
			free(arr1);
			return (1);
		}
		i++;
	}
	printf("Test passed: all elemets are initialesed to zero\n");
	free(arr1);
	return(0);
}
*/
