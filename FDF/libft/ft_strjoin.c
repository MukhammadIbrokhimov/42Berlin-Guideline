/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:57:01 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/12 19:14:47 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new_string;
	size_t		i;
	size_t		j;

	new_string = NULL;
	new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_string)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			new_string[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			new_string[i + j] = s2[j];
			j++;
		}
	}
	new_string[i + j] = '\0';
	return (new_string);
}

// int main(void)
// {
// 	char	*s1 = "my favorite animal is";
// 	char *s2 = " ";
// 	char *s3 = "horse";
// 	char *s4 = ft_strjoin(ft_strjoin(s1, s2), s3);
// 	printf("str:  %s", s4);
// }
