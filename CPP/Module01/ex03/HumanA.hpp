/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukhammad-ibrokhimov <mukhammad-ibrokhi    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:25:03 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 18:09:08 by mukhammad-i      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA{
    private:
        Weapon  *weapon;
        std::string name;

    public:
        HumanA(std::string _name, Weapon& _type);
        ~HumanA();
        void    attack(void);
};