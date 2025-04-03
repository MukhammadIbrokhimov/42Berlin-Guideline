/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:55:38 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/09 16:39:30 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	is_rejected(char c, const char *rejected)
{
	int	i;

	i = 0;
	while (rejected[i])
	{
		if (rejected[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (!(is_rejected(s[i], reject)))
		i++;
	return (i);

}

// int	main(int argc, char **argv)
// {
// 	char s1[] = "   leading spaces";
// 	char s2[] = "lspaces";



// 	printf("FT: %ld\n", ft_strcspn(s1, s2));
// 	printf("FT: %ld\n", strcspn(s1, s2));
// }
