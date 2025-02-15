/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:18:06 by mukibrok          #+#    #+#             */
/*   Updated: 2024/10/01 12:44:17 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

//int	main(void)
//{
//	ft_print_reverse_alphabet();
//}

void	ft_print_reverse_alphabet(void)
{
	char	z;

	z = 122;
	while (z >= 'a')
	{
		write(1, &z, 1);
		z--;
	}
}
