/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:39:13 by gansari           #+#    #+#             */
/*   Updated: 2024/10/15 17:52:32 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char *s1 = "ab";
    char *s2 = "ab";
    char *s3 = "ac";
    char *s4 = "ad";


    printf("s1 - s2\n");
    printf("My result:%d\n", ft_strcmp(s1, s2));
    printf("Original:%d\n", strcmp(s1,s2));
    printf("s4 - s3\n");
    printf("My result:%d\n", ft_strcmp(s3,s4));
    printf("Original: %d\n", strcmp(s3,s4));
    printf("s4 - s2\n");
    printf("My result:%d\n", ft_strcmp(s4,s2));
    printf("Original:%d\n", strcmp(s4,s2));

    return 0;
}
*/
