/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:43:35 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:43:45 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[50] = "Hello, world!";
	char	str2[50] = "Hello, world!";

	printf("the str before: %s\n", str1);
	memset(str1, 'A', 5);
	printf("the original memset: %s\n", str1);
	ft_memset(str2, 'A', 5);
	printf("my ft_memset: %s\n", str2);
	return (0);
	
}
*/
