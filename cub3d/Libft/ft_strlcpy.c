/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:44:01 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:44:08 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello, world";
	char	dest1[50];
	char	dest2[50];

	printf("The src is : %s\n", src);
	strlcpy(dest1, src, 6);
	printf("The result of original function is : %s\n", dest1);
	ft_strlcpy(dest2, src, 6);
	printf("The result of my function is : %s\n", dest2);
	return (0);
}
*/
