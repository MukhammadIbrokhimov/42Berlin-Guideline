/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:10:44 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 11:34:08 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	solve(unsigned int a, unsigned int b)
{
	unsigned int	tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / solve(a, b)) * b);
}
int main(void)
{
    unsigned int a = 12;
    unsigned int b = 15;

    printf("LCM of %u and %u is %u\n", a, b, lcm(a, b));
    return 0;
}
