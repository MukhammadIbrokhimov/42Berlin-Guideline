/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:54:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 14:49:37 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name){
		_hitPoints = FragTrap::_hitPoints;
		_energyPoints = ScavTrap::_energyPoints;
		_AttackDamage = FragTrap::_AttackDamage;
	}

void	DiamondTrap::whoAmi(void){
	std::cout << "I am DiamondTrap" << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):ClapTrap(other), FragTrap(other), ScavTrap(other)  {
	this->_name = other._name;
	this->_AttackDamage = other._AttackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other){
	if (this != &other){
		this->_name = other._name;
		this->_AttackDamage = other._AttackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;
	}
	std::cout << "DiamondTrap copy operator constructor called\n";
	return *this;
}

DiamondTrap::~DiamondTrap() {}


