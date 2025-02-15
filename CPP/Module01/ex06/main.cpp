/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:34:42 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/15 12:37:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Please provide with correct argument" << std::endl;
		return (1);
	}
	std::string command	= argv[1];
	std::transform(command.begin(), command.end(), command.begin(), ::toupper);
	
	Harl	harl;
	harl.complain(command);
}