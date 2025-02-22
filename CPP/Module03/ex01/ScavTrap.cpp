/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:47:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 18:46:27 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	setAttackDamage(20);
	setHitPoints(100);
	setEnergyPoints(50);
	std::cout << "Constructor ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap desttructor calles\n";
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
	std::cout << "ScavTrap " << other.getName() << " copy constructor called!\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other){
	if (this != &other){
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());
		this->setName(other.getName());
	}
	return *this;
}

void	ScavTrap::guardGate(void){
	std::cout << " ScavTrap is now in Gate keeper mode." << std::endl;
}