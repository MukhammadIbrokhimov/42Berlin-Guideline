/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:21:35 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 14:13:09 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
};

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called\n";
}

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
	std::cout << RED << getName() << " is dead and can't attack.\n" << RESET;
	return;
	}
	if (_energyPoints > 0) {
		std::cout << YELLOW << "ScavTrap " << getName() << " attacks " << target 
			<< ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	} else {
		std::cout << RED << getName() << " has no energy left to attack.\n" << RESET;
	}
}

void ScavTrap::guardGate()
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot enter Gate keeper mode because it is destroyed!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}