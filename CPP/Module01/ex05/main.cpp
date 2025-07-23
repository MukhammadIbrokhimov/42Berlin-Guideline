/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:04:49 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/09 12:38:55 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc < 2){
		std::cout << RED << "Give me only one level" << RESET << std::endl;
		return 1;
	}

	Harl harl;

	harl.complain(argv[1]);
}