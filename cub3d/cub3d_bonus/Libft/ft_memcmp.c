/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:45 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:45:50 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "GhazAleh";
	char	str2[] = "GhazaleH";

	printf("The original: %d\n", memcmp(str1, str2, 3));
	printf("Mine: %d\n", ft_memcmp(str1, str2, 3));
	printf("The original: %d\n", memcmp(str1, str2, 5));
	printf("Mine: %d\n", ft_memcmp(str1, str2, 5));
	return (0);
}
*/
