/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:24:30 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/11 19:48:53 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	ft_test(unsigned int, char *v)
// {
// 	if (*v >= 96 && *v <= 122)
// 		*v -= 32;
// }

// int	main(void)
// {
// 	char str[] = "school";
// 	ft_striteri(str, ft_test);
// 	printf("tet: %s", str);
// }
