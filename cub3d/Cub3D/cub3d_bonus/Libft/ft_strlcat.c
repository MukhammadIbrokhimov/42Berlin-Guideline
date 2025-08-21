/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:55 by gansari           #+#    #+#             */
/*   Updated: 2024/11/14 11:11:45 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	si;
	size_t	di;

	si = ft_strlen((char *)src);
	if (!dst && size == 0)
		return (si);
	d = ft_strlen(dst);
	di = d;
	if (size <= di)
		return (size + si);
	s = 0;
	while (src[s] && d < size - 1)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (di + si);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = ", world!";
	char	dst1[80] = "Hello";
	char	dst2[80] = "Hello";

	//printf("The initial destination: %s\n", dst1);
	//ft_strlcat(dst1, src, 15);
	printf("The initial destination: %ld\n", ft_strlcat(dst1, src, 9));
	printf("The result destination: %s\n", dst1);
	//strlcpy(dst2, src, 15);
	printf("The result destination: %s\n", dst2);
	return (0);
}
*/
