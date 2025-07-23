/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:38:40 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/08 12:21:15 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	int	i = 0;
	while (++i < argc)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (islower(argv[i][j]))
				std::cout << static_cast<char> (std::toupper(argv[i][j]));
			else
				std::cout << argv[i][j];
			j++;
		}
	}
	std::cout << std::endl;
}
