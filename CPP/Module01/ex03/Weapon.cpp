/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:09:50 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/13 20:44:55 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "iostream"

Weapon::Weapon(){}
Weapon::Weapon(std::string type): _type(type){};

Weapon::~Weapon(){}

std::string Weapon::getType(void) const{
	return _type;
}

void	Weapon::setType(std::string weapon){
	 _type = weapon;
}
