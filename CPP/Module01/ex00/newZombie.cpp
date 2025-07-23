/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:15:37 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 03:50:54 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie *zombie = new Zombie(name);
    return (zombie);
}