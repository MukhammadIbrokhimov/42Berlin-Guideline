/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:04:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/09 12:38:42 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << GREEN <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< RESET << std::endl;
}

void	Harl::info(void) {
	std::cout << BLUE <<
	"I cannot believe adding extra bacon costs more money. You didnt put"
	" enough bacon in my burger! If you did, I wouldnt be asking for more!"
	<< RESET << std::endl;
}

void	Harl::warning(void) {
	std::cout << YELLOW <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for"
	" years, whereas you started working here just last month."
	<< RESET << std::endl;
}

void	Harl::error(void) {
	std::cout << RED <<
	"This is unacceptable! I want to speak to the manager now."
	<< RESET << std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << RED << "no any given level here !" << RESET << std::endl;
}