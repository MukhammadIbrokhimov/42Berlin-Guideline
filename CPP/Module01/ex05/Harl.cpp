/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:35:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/15 11:20:59 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void ){
	std::cout <<
	"I love having extra bacon for my \n \
	7XL-double-cheese-triple-pickle-specialketchup burger. \n \
	I really do!\n" << std::endl;
}

void Harl::info( void ){
	std::cout <<
	"I cannot believe adding extra bacon costs more money. \n \
	You didn’t put enough bacon in my burger! If you did, \n \
	I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void ){
	std::cout << 
	"I think I deserve to have some extra bacon for free. \n \
	I’ve been coming for years whereas you started working \n \
	here since last month.\n" << std::endl;
}

void Harl::error( void ){
	std::cout <<
	"This is unacceptable! I want to speak to the manager now." \
	<< std::endl;
}

void Harl::complain( std::string level ){
	typedef	unsigned long ul;
	typedef void(Harl::*myFunction)();

	struct levell{
		std::string name;
		myFunction	funct;
	};

	levell	compLevel[] = {
		{"debug", &Harl::debug},
		{"info", &Harl::info},
		{"warning", &Harl::warning},
		{"error", &Harl::error},
	};
	// c++11;
	//for (levell &lev : compLevel){
	//	if (lev.name == level){
	//		(this->*(lev.funct))();
	//		break;
	//	}
	//}

	for (ul i = 0; i < sizeof(compLevel) / sizeof(compLevel[0]); i++){
		if (level == compLevel[i].name){
			if (compLevel[i].name == level){
				(this->*(compLevel[i].funct))();
				break;
			}
		}
	}
}