/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:31:33 by hta-rezi2         #+#    #+#             */
/*   Updated: 2025/07/06 04:12:05 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name): name(_name) {};
Zombie::Zombie(){};
Zombie::~Zombie(){
    std::cout << GREEN << name << RED
            << " destroyed !" 
            << RESET << std::endl;
};

void    Zombie::announce(void){
    std::cout << GREEN << name 
        << CYAN << ": BraiiiiiiinnnzzzZ..."
        << RESET << std::endl;
}