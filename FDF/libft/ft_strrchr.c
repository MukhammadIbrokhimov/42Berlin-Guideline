/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:08:27 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/17 14:58:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;
	int	end;

	n = ft_strlen(s);
	end = n;
	if ((char)c == '\0')
		return ((char *)s + end);
	while (n-- >= 0)
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
	}
	return (NULL);
}

// void	test_ft_strchr(const char *s, int c)
// {
// 	char	*result_ft;
// 	char	*result_orig;

// 	result_orig = strrchr(s, c);
// 	result_ft = ft_strrchr(s, c);
// 	printf("Testing with string: \"%s\" and character: '%c'\n", s, c);
// 	printf("Original `strchr`: %s\n", result_orig ? result_orig : "(null)");
// 	printf("Your `ft_strchr`: %s\n", result_ft ? result_ft : "(null)");
// 	if (result_ft == result_orig)
// 	{
// 		printf("✅ Both functions returned the same result.\n");
// 	}
// 	else
// 	{
// 		printf("❌ Results differ!\n");
// 	}
// 	printf("------------------------------\n");
// }

// int	main(void)
// {
// 	test_ft_strchr("abbbbbbbbbb!", 'a');
// 	test_ft_strchr("Hello, World!", 'H');
// 	test_ft_strchr("Hello, World!", '!');
// 	test_ft_strchr("Hello, World!", 'z');
// 	test_ft_strchr("Hello, World!", '\0');
// 	test_ft_strchr("", 'a');
// 	test_ft_strchr(NULL, 'a');
// 	return (0);
// }
