/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:29:05 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/09 20:12:13 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	int		i;

	arr = NULL;
	arr = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = (*f)(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

// char to_upper(unsigned int i, char c)  // No index here
// {
//     if (c >= 'a' && c <= 'z')
//         return c - 32;  // Convert to uppercase
//     return c;  // Return the character unchanged
// }
// int main(void)
// {
//     const char *s = "hello world!";
//     char *result = ft_strmapi(s, ft_toupper);

//     if (result)
//     {
//         printf("Transformed string: %s\n", result);
//         free(result); // Don't forget to free the memory
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }
