/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:05:52 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/21 21:07:14 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _AttackDamage(0) {
	std::cout << "\033[36mClapTrap Constructor called for " << _name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _AttackDamage(0) {
	std::cout << "\033[36mClapTrap Default Constructor called\033[0m" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cerr << "\033[31mClapTrap Destructor called for " << _name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _AttackDamage(other._AttackDamage) {
	std::cout << "\033[35mClapTrap Copy Constructor called\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_AttackDamage = other._AttackDamage;
	}
	std::cout << "\033[35mClapTrap Copy Assignment Operator called\033[0m" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " 
	          << _AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already at 0 hit points!" << std::endl;
		return;
	}
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " has been defeated!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage, remaining HP: " << _hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has no energy points to repair itself!" << std::endl;
		return;
	}
	_energyPoints -= 1; // Only use 1 energy point per repair
	_hitPoints += amount;
	if (_hitPoints > 10) {
		_hitPoints = 10;
	}
	std::cout << "ClapTrap " << _name << " repaired itself, HP: " << _hitPoints << std::endl;
}

void ClapTrap::aboutClapTrap() {
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack Damage: " << _AttackDamage << std::endl;
}

// Setters
void ClapTrap::setHitPoints(unsigned int value) { _hitPoints = value; }
void ClapTrap::setEnergyPoints(unsigned int value) { _energyPoints = value; }
void ClapTrap::setAttackDamage(unsigned int value) { _AttackDamage = value; }
void ClapTrap::setName(std::string name) { _name = name; }

// Getters
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage() const { return _AttackDamage; }
std::string ClapTrap::getName() const { return _name; }
