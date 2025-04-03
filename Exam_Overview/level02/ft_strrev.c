/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:23:38 by mukibrok          #+#    #+#             */
/*   Updated: 2024/12/09 17:34:42 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int	length;
	int i;
	char tmp;

	length = ft_strlen(str) - 1;
	i = 0;
	while(i < length)
	{
		tmp = str[length];
		str[length] = str[i];
		str[i] = tmp;
		i++;
		length--;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	char str[] = "Siddiq";
	printf("%s\n", ft_strrev(argv[1]));
}
