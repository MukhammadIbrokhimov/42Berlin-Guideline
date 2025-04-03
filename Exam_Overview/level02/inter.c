/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:35:51 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 21:25:59 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_char(char *s, char *s2, int *arr)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s2[j])
		{
			if (arr[(int)s[i]] == 0 && s[i] == s2[j])
			{
				arr[(int)s[i]] = 1;
				write(1, &s[i], 1);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	arr[1024] = {0};

	if (argc == 3)
	{
		print_char(argv[1], argv[2], arr);
	}
	write(1, "\n", 1);
}

if (!arr) return (NULL);
