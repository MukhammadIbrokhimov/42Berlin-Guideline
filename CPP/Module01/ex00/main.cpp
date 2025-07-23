/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:15:06 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/09 18:41:57 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie  zombie("Foo");
	zombie.announce();

	Zombie *anotherZomb = newZombie("alocZombie");
	std::cout << YELLOW << "Successfully Zombie allocated"
			<< RESET << std::endl;
	delete(anotherZomb);
	randomChump("radomZombie");
}