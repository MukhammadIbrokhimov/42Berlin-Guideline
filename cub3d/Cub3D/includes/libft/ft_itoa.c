/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:16:25 by gansari           #+#    #+#             */
/*   Updated: 2024/11/14 15:09:50 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_char(char *str, long num, size_t len)
{
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;

	num = n;
	len = num_len(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
		str = ft_char(str, num, len);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	number = 9;
// 	char	*str;
// 	str = ft_itoa(number);
// 	printf("The converted number is: %s\n", str);
// 	printf("%ld\n", ft_strlen(str));
// 	free(str);
// 	return (0);
// }
