/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:34:35 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/15 12:42:38 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void) {
	std::cout << "\033[1;36m"   // Bright cyan
			<< "--------------------------------------------" << std::endl
			<< "[ DEBUG ]" << std::endl
			<< "I love having extra bacon for my" << std::endl
			<< "7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
			<< "I really do!" << std::endl
			<< "--------------------------------------------" << std::endl
			<< "\033[0m";    // Reset color
}

void Harl::info(void) {
	std::cout << "\033[1;32m"   // Bright green
			<< "--------------------------------------------" << std::endl
			<< "[ INFO ]" << std::endl
			<< "I cannot believe adding extra bacon costs more money." << std::endl
			<< "You didn’t put enough bacon in my burger! If you did," << std::endl
			<< "I wouldn’t be asking for more!" << std::endl
			<< "--------------------------------------------" << std::endl
			<< "\033[0m";
}

void Harl::warning(void) {
	std::cout << "\033[1;33m"   // Bright yellow
			<< "--------------------------------------------" << std::endl
			<< "[ WARNING ]" << std::endl
			<< "I think I deserve to have some extra bacon for free." << std::endl
			<< "I’ve been coming for years whereas you started working" << std::endl
			<< "here since last month." << std::endl
			<< "--------------------------------------------" << std::endl
			<< "\033[0m";
}

void Harl::error(void) {
	std::cout << "\033[1;31m"   // Bright red
			<< "--------------------------------------------" << std::endl
			<< "[ ERROR ]" << std::endl
			<< "This is unacceptable! I want to speak to the manager now." << std::endl
			<< "--------------------------------------------" << std::endl
			<< "\033[0m";
}

void Harl::complain(std::string command){
	typedef	void(Harl::*MyFunct)();
	typedef	unsigned long	ul;

	struct Level{
		std::string	name;
		MyFunct	funct;
	};

	Level commands[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};
	ul	sizeCommand = sizeof(commands) / sizeof(commands[0]);
	ul j = 0;;
	for (ul i = 0; i < sizeCommand; i++){
		if (commands[i].name == command){
			j = i;
			for (; j < sizeCommand; j++){
				(this->*(commands[j].funct))();
			}
			break;
		}
	}
	if (j == 0){
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "[ " << command << " ]" << std::endl;
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;		
	}
}