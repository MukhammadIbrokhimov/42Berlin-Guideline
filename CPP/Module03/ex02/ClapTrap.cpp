/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:21:08 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 13:39:45 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// assigning value for private attribute
ClapTrap::ClapTrap()
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called\n";
}

// constructors
ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) 
	: _name(other._name), _hitPoints(other._hitPoints),
		_energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy assignment operator called\n";
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

// destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called\n";
}

// getter

std::string	ClapTrap::getName(void) const { return (_name); }
int			ClapTrap::getHitPoints(void) const { return (_hitPoints); }
int			ClapTrap::getEnergyPoints(void) const { return (_energyPoints); }
int			ClapTrap::getAttackDamage(void) const { return (_attackDamage); }

// extra functions

void ClapTrap::printAbout(void) {
	std::cout << CYAN << getName() << " STATUS:\n"
		<< "_hitPoints: " << _hitPoints << "\n"
		<< "_energyPoints: " << _energyPoints << "\n"
		<< "_attackDamage: " << _attackDamage << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << RED << getName() << " is dead and can't attack.\n" << RESET;
		return;
	}
	if (_energyPoints > 0) {
		std::cout << YELLOW << "ClapTrap " << getName() << " attacks " << target 
			<< ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	} else {
		std::cout << RED << getName() << " has no energy left to attack.\n" << RESET;
	}
	printAbout();
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << RED << getName() << " is already dead.\n" << RESET;
		return;
	}
	std::cout << RED << getName() << " takes " << amount << " points of damage!" << RESET << std::endl;
	if (_hitPoints <= (int) amount)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	if (_hitPoints == 0) {
		std::cout << RED << getName() << " has died.\n" << RESET;
	}
	printAbout();
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << RED << getName() << " is dead and can't repair itself.\n" << RESET;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << RED << getName() << " has no energy left to repair.\n" << RESET;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << GREEN << getName() << " repairs itself for " << amount << " hit points!" << RESET << std::endl;
	printAbout();
}
