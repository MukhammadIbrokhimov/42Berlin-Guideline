/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:44:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 12:50:28 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieClass.hpp"

Zombie*	newZombie(std::string name){
	return new Zombie(name);
}

void	randomChump(std::string name){
	Zombie	*new_zombie = newZombie(name);
	new_zombie->announce();
	delete new_zombie;
}

int main(void){
	Zombie z1("Walker");
	z1.announce();
	randomChump("Harry");
}