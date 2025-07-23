/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:21:35 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 14:59:35 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap Default constructor called\n";
	this->_hitPoints = 100;
	this->_energyPoints = 10;
	this->_attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	std::cout << "FragTrap Copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called\n";
}

void	FragTrap::highFivesGuys(void){
	std::cout << " high fives requested\n";
}

void	FragTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
	std::cout << RED << getName() << " is dead and can't attack.\n" << RESET;
	return;
	}
	if (_energyPoints > 0) {
		std::cout << YELLOW << "FragTrap " << getName() << " attacks " << target 
			<< ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	} else {
		std::cout << RED << getName() << " has no energy left to attack.\n" << RESET;
	}
}

