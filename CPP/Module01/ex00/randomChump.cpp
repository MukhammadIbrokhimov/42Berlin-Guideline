/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:15:41 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 03:54:31 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name ){
    Zombie *zombie = newZombie(name);
    zombie->announce();
    delete(zombie);
}