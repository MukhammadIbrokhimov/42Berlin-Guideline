/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:47:34 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 18:11:02 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name): weapon(NULL), name(_name) {}

HumanB::~HumanB(){};

void HumanB::attack() {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}

void    HumanB::setWeapon(Weapon& _type){
    weapon = &_type;
}
