/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:05 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:45:11 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[80] = "Hello, world!";
	char	str2[80] = "Hello, world!";

	printf("The str is: %s\n", str1);
	bzero(str1, 5);
	printf("the original function result: %s\n", str1);
	ft_bzero(str2, 5);
	printf("my function result: %s\n", str2);
	return (0);
}
*/
