/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:32:20 by gansari           #+#    #+#             */
/*   Updated: 2024/11/14 17:10:40 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*output;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	output = (char *)malloc(len + 1);
	if (!output)
		return (NULL);
	i = 0;
	while (i < len)
	{
		output[i] = (*f)(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
/*
#include <stdio.h>

char	transform(unsigned int i, char c)
{
	return c + (char)i;
}

void test_ft_strmapi() {

	char	*input1 = "abcd";
	char	*output1 = ft_strmapi(input1, transform);

	if (output1)
	{
		printf("Test 1 Output: %s\n", output1);
		free(output1);
	}
	else
		printf("Test 1 Failed: Memory allocation error.\n");
	char	*input2 = "";
	char	*output2 = ft_strmapi(input2, transform);

	if (output2)
	{
		printf("Test 2 Output: '%s'\n", output2);
		free(output2);
	}
	else
		printf("Test 2 Failed: Memory allocation error.\n");
	char	*output3 = ft_strmapi(NULL, transform);
	if (output3 == NULL)
	{
		printf("Test 3 Passed: Null input handled correctly.\n");
	}
	else
		printf("Test 3 Failed: Null input was not handled properly.\n");
}

int	main(void)
{
	test_ft_strmapi();
	return (0);
}
*/