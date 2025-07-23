/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:23:37 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 18:10:06 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _type):weapon(&_type), name(_name){};

HumanA::~HumanA(){};

void HumanA::attack() {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}