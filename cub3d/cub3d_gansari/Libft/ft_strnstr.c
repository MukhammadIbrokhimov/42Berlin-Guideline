/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:50:17 by gansari           #+#    #+#             */
/*   Updated: 2024/11/13 16:50:23 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && (i + j) < len && big[i + j] == little[j])
				j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	big[] = "salam azizam, azizam salam";
	char	little[] = "hi";

	printf("My function: %s\n", ft_strnstr(big, little, 15));
	return (0);
}
*/
