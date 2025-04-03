/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:42:09 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/09 17:21:46 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	is_pbrk(char c, const char *s1)
{
	while (*s1)
	{
		if (c == *s1)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if(is_pbrk(s1[i], s2))
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
#include <stdio.h>
#include <string.h>

// Declare your ft_strpbrk function
char *ft_strpbrk(const char *s1, const char *s2);

void test_strpbrk(const char *s1, const char *s2) {
    // Standard strpbrk
    char *std_result = strpbrk(s1, s2);

    // Your ft_strpbrk
    char *ft_result = ft_strpbrk(s1, s2);

    printf("Testing strpbrk(\"%s\", \"%s\"):\n", s1, s2);

    if (std_result) {
        printf("  strpbrk    -> Match: '%c', Substring: \"%s\"\n", *std_result, std_result);
    } else {
        printf("  strpbrk    -> No match found.\n");
    }

    if (ft_result) {
        printf("  ft_strpbrk -> Match: '%c', Substring: \"%s\"\n", *ft_result, ft_result);
    } else {
        printf("  ft_strpbrk -> No match found.\n");
    }

    // Compare results
    if (std_result == ft_result) {
        printf("  Result: ✅ Match\n\n");
    } else {
        printf("  Result: ❌ Mismatch\n\n");
    }
}

int main() {
    // Test cases
    test_strpbrk("hello world", "aeiou"); // Match: 'e'
    test_strpbrk("hello world", "xyz");   // No match
    test_strpbrk("123@#%", "@#");         // Match: '@'
    test_strpbrk("abcdef", "fedcba");     // Match: 'a'
    test_strpbrk("", "abc");              // No match
    test_strpbrk("hello", "");            // No match
    test_strpbrk("Hello", "h");           // No match (case-sensitive)
    test_strpbrk("abcdef", "xyzc");       // Match: 'c'

    return 0;
}
