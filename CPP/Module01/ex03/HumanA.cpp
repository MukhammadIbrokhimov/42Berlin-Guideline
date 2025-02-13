/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:51 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/13 20:31:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::~HumanA() {};

HumanA::HumanA(std::string name, Weapon &weapon)
		: _name(name), _typeOfWeapon(weapon){};

void	HumanA::attack(void){
	std::cout << _name 
			<< " attacks with their " << _typeOfWeapon.getType()
			<< std::endl;
}