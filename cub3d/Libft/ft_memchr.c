/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:43:16 by gansari           #+#    #+#             */
/*   Updated: 2024/11/14 10:54:56 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*first;
	size_t			i;

	str = (unsigned char *)s;
	first = NULL;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
		{
			first = str;
			return (first);
		}
		str++;
		i++;
	}
	return (first);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str[] = "Ghazaleh Ansari";
	char	c = 'a';

	printf("The original function result: %p\n", memchr(str, c, 4));
	printf("My function result: %p\n", ft_memchr(str, c, 4));
	return (0);
}
*/
