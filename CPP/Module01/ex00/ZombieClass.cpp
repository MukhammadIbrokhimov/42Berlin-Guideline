/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:45:14 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 12:50:46 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieClass.hpp"

Zombie::Zombie(std::string name) : _name(name) {};

Zombie::~Zombie(void){
	std::cout << _name << " Destroyed" << std::endl;
}

std::string Zombie::GetName(void){
	return (_name);
}

void	Zombie::announce(void){
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}