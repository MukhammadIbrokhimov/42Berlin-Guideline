/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:28:13 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/26 18:11:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long ft_atol(const char *s, int *error)
{
	long number = 0;
	int sign = 1;

	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		number = number * 10 + (*s - '0');
		s++;
		if ((sign == 1 && number > INT_MAX) || (sign == -1 && -number < INT_MIN))
			return (*error = -1, 0);
	}
	return (sign * number);
}


// int	main(int argc, char **argv)
// {
// 	printf("ft_atoi: %ld\n", ft_atol(argv[1]));
// 	printf("atoi: %ld\n", atol(argv[1]));
// }
