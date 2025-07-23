/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:27:16 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 18:10:20 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "Weapon.hpp"

class HumanB{
    private:
        Weapon  *weapon;
        std::string name;

    public:
        HumanB(std::string _name);
        ~HumanB();

        void    setWeapon(Weapon& _type);
        void    attack(void);
};