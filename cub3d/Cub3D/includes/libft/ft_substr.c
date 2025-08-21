/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:57:24 by gansari           #+#    #+#             */
/*   Updated: 2024/12/04 00:34:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	substr[len] = '\0';
	return (substr);
}
/*
#include <stdio.h>

	int	main(void)
	{
		char	*original = "Hello, World!";
		char	*substr;

		substr = ft_substr(original, 7, 5);
		printf("Test1: %s\n", substr);
		free(substr);
		substr = ft_substr(original, 20, 5);
		printf("Test2: %s\n", substr);
		free(substr);
		substr = ft_substr(original, 7, 50);
		printf("Test3: %s\n", substr);
		free(substr);
		substr = ft_substr(original, 7, 0);
		printf("Test4: %s\n", substr);
		free(substr);
		substr = ft_substr("", 0, 5);
		printf("Test5: %s\n", substr);
		free(substr);
		substr = ft_substr(NULL, 0, 5);
		printf("Test6: %s\n", substr ? substr : "NULL");
		free(substr);
		return (0);
	}
*/
