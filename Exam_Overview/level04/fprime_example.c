/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime_example.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:40:14 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 14:40:21 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    fprime(int n)
{
    int factor = 2;
    int first = 1; // To manage the '*' separator

    if (n == 1)
    {
        printf("1");
        return;
    }
    while (n > 1)
    {
        if (n % factor == 0)
        {
            if (!first)
                printf("*");
            printf("%d", factor);
            n /= factor;
            first = 0; // After the first factor, '*' is needed
        }
        else
            factor++;
    }
}

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("\n");
        return (0);
    }
    int n = atoi(argv[1]);
    if (n <= 0)
    {
        printf("\n");
        return (0);
    }
    fprime(n);
    printf("\n");
    return (0);
}
