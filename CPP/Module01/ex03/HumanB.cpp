/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:42:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/13 20:41:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
	: _name(name), _typeOfWeapon(NULL){}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &weapon){
	_typeOfWeapon = &weapon;
}

void HumanB::attack() {
	if (_typeOfWeapon)
		std::cout << _name << " attacks with their " << _typeOfWeapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon!" << std::endl;
}