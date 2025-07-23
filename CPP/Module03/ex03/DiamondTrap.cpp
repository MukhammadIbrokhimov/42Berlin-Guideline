/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:38:47 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 15:31:15 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default") {
	std::cout << "DiamondTrap constructor called\n";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap constructor called\n";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
		std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called\n";
}

// Special ability - shows both names
void DiamondTrap::whoAmI()
{
	if (this->_hitPoints == 0)
	{
		std::cout << "DiamondTrap cannot identify itself because it is destroyed!" << std::endl;
		return;
	}
	
	std::cout << "DiamondTrap identity crisis!" << std::endl;
	std::cout << "My DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getDiamondName() const
{
	return this->_name;  // DiamondTrap's own name
}

std::string DiamondTrap::getClapTrapName() const
{
	return ClapTrap::_name;  // Access the shadowed ClapTrap name
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}