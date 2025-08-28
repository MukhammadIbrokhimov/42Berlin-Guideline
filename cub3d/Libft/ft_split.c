/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:49:56 by gansari           #+#    #+#             */
/*   Updated: 2024/11/19 12:50:00 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **arr, int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		arr[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!arr[word])
			return (free_array(arr, word));
		ft_putword(arr[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	arr[word] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!arr)
		return (0);
	arr = ft_split_words(s, c, arr, num_words);
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Hello!";
	char	delimiter = ' ';

	char	**result = ft_split(str, delimiter);

	if (!result)
	{
		printf("Error: ft_split returned NULL\n");
		return (1);
	}

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]); 
	}

	free(result);
	return (0);
}
*/