/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:47:24 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:47:30 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("The result is %d\n", ft_isdigit('1'));
	printf("The result is %d\n", isdigit('1'));
	printf("The result is %d\n", ft_isdigit('g'));
	printf("The result is %d\n", isdigit('g'));
}
*/
