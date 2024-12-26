/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:57:16 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/15 09:58:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	is_space(int c)
// {
// 	return ((c == 32) || (c >= 9 && c <= 13));
// }

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	j;
	size_t	i;

	if (*find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && find[j] && i + j < len && str[i + j] == find[j])
			j++;
		if (find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

// int	main(int argc, char **argv)
// {
// 	char *str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 17);
// 	printf("found %s\n", str);
// }