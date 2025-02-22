/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:54:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 22:57:38 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: _name(name), FragTrap(name), ScavTrap(name), ClapTrap(name + "_clap_name"){
		_hitPoints = FragTrap::_hitPoints;
		_energyPoints = ScavTrap::_energyPoints;
		_AttackDamage = FragTrap::_AttackDamage;
	}

void	DiamondTrap::whoAmi(void){
	std::cout << "I am DiamondTrap" << _name << std::endl;
}


