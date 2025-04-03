/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:05:04 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/11 21:21:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_reverse(char *s)
{
	int	end;
	int	len;
	int i;
	int start;

	end = ft_strlen(s) - 1;
	while (end > 0)
	{
		while (ft_isspace(s[end]) && end >= 0)
		{
			write(1, &s[end], 1);
			end--;
		}
		len = 0;
		while (!ft_isspace(s[end]) && end >= 0)
		{
			end--;
			len++;
		}
		i = 0;
		start = end + 1;
		while (!ft_isspace(s[start]) && s[start] != '\0' && i <= len)
		{
			write(1, &s[start], 1);
			start++;
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_reverse(argv[1]);
	write(1, "\n", 1);
}
