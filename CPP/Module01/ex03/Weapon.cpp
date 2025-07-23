/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:01:58 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/09 18:51:04 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type): type(_type){};
Weapon::~Weapon(){};

const std::string& Weapon::getType(void) {
	return type; 
};

void    Weapon::setType(std::string _type){
    type = _type;
};
