/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:07:55 by gansari           #+#    #+#             */
/*   Updated: 2024/11/14 17:31:37 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen((const char *)s);
	i = 0;
	while (i < len)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(unsigned int i, char* c)
{
	write(1, c, 1);
	printf(" - %d\n", i);
}

int	main(void)
{
	char	*str = "Ghazaleh";
	ft_striteri(str, ft_putchar);
	return (0);
}
*/