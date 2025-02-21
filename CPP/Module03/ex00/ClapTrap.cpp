/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:13:03 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/21 20:41:47 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "\033[36m" << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cerr << "\033[31mDestructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
: _name(other._name), _hitPoints(other._hitPoints),
_energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "\033[36m" << "Copy Constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &other){
	if (this != &other){
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack( const std::string &target ){
	if (_energyPoints == 0){
		std::cout << "ClapTrap " << _name
				<< " no energy to attack"
				<< std::endl;
		return ;
	}
	_energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has already been destroyed!" << std::endl;
		return;
	}
	
	if (amount >= _hitPoints) {  // If damage >= current HP, set to 0
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " took massive damage and is destroyed!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage! Remaining HP: " << _hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ){
	if (_energyPoints == 0){
		std::cout << "ClapTrap " << _name << "No energy points to repair itself"
					<< std::endl;
		return ;
	}
	_energyPoints -= amount;
	if (_hitPoints < 10){
		_hitPoints += amount;
		if (_hitPoints > 10){
			_hitPoints = 10;
		}
	}
	std::cout << "ClapTrap " << _name << "repaired itself" << std::endl;
}

void	ClapTrap::aboutClapTrap(void){
	std::cout << "Hitpoints: " << _hitPoints << std::endl;
	std::cout << "_energyPoints: " << _energyPoints << std::endl;
	std::cout << "AttackDamage: " << _attackDamage << std::endl;
}