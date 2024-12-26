/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:57:15 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/15 09:30:19 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(long n, int *negative)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		*negative = 1;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		negative;
	size_t	size;
	long	num;
	char	*number;

	num = n;
	negative = 0;
	size = ft_length(num, &negative);
	number = (char *)malloc(sizeof(char) * (size + 1));
	if (!number)
		return (NULL);
	number[size] = '\0';
	if (num == 0)
		number[0] = '0';
	if (negative)
		num = -num;
	while (num > 0)
	{
		number[--size] = (num % 10) + '0';
		num /= 10;
	}
	if (negative)
		number[0] = '-';
	return (number);
}

// int	main(void)
// {
// 	char	*arr;

// 	arr = ft_itoa(0);
// 	printf("arr: %s\n", arr);
// 	free(arr);
// 	return (0);
// }
