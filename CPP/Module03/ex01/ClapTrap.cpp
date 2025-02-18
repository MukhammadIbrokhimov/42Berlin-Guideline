/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:13:03 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 15:00:55 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

unsigned int ClapTrap::_hitPoints = 10;
unsigned int ClapTrap::_energyPoints = 10;
unsigned int ClapTrap::_AttackDamage = 10;

ClapTrap::ClapTrap(std::string name): _name(name){
	std::cout << "\033[36m" << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cerr << "\033[31mDestructor called\033[0m" << std::endl;
}

void	ClapTrap::attack( const std::string &target ){
	if (_energyPoints == 0){
		std::cout << "ClapTrap " << _name
				<< " no energy to attack"
				<< std::endl;
		return ;
	}
	_energyPoints -= 1;
	_AttackDamage -= 1;
	std::cout << "ClapTrap " << _name << " attacks "
			<< target << " ,causing " << 10 - _AttackDamage
			<< " points of damage!"
			<< std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ){
	_hitPoints -= amount;
	if (_hitPoints <= 0){
		std::cout << "ClapTrap " << _name
			<< "hitted a lot and spend whole points"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " took damage amount"
				<< amount << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ){
	if (_energyPoints <= 0){
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