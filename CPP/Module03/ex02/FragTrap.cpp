/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:42:43 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 21:22:49 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys(void){
	std::cout << " high fives requested\n";
}

FragTrap&	FragTrap::operator=(const FragTrap &other){
	std::cout << "Copy operator called\n";

	if (this != &other){
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());
		this->setName(other.getName());
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other){
	std::cout << "FragTrap copy were called\n";
}



