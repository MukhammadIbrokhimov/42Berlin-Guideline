/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:41 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:49:46 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buffer1[20] = "Hello, World!";
	char	buffer2[20] = "Hello, World!";
	char	buffer3[20] = "Hello, World!";
	char	buffer4[20] = "Hello, World!";

	ft_memmove(buffer1 + 7, buffer1, 5);
	printf("non-overlapping My function: %s\n", buffer1);
	memmove(buffer2 + 7, buffer2, 5);
	printf("non-overlapping Original function: %s\n", buffer2);

	ft_memmove(buffer3, buffer3 + 7, 6);
	printf("overlapping My function: %s\n", buffer3);
	memmove(buffer4, buffer4 + 7, 6);
	printf("overlapping Original function: %s\n", buffer4);
	return (0);
}
*/
