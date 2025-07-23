/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:04:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/09 18:58:23 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc < 2){
		std::cout << RED << "Give me only one level" << RESET << std::endl;
		return 1;
	}

	Harl harl;

	harl.harlFilter(argv[1]);
}