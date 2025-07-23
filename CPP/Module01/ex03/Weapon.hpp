/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:01:52 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/09 18:50:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon{
    private:
        std::string type;
    
    public:
        Weapon(std::string _type);
        ~Weapon();
        const std::string& getType(void);
        void setType(std::string _type);
};
