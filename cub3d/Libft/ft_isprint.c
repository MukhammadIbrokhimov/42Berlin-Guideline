/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:49:24 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:49:29 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", isprint(' '));
	printf("%d\n", ft_isprint('~'));
	printf("%d\n", isprint('~'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", isprint('\n'));
	return(0);
}
*/
