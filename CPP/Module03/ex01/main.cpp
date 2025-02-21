/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:57:55 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/21 20:59:14 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void testScavTrap()
{
	std::cout << "\n--- ScavTrap Constructor Test ---\n";
	ScavTrap scav("Scavvy");

	std::cout << "\n--- Testing attack() ---\n";
	scav.attack("target1");

	std::cout << "\n--- Testing takeDamage() ---\n";
	scav.takeDamage(30);

	std::cout << "\n--- Testing beRepaired() ---\n";
	scav.beRepaired(20);

	std::cout << "\n--- Testing guardGate() ---\n";
	scav.guardGate();
	
	std::cout << "\n--- ScavTrap Destructor Test ---\n";
}

int main()
{
	testScavTrap();
	return 0;
}