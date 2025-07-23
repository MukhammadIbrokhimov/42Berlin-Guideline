/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:36 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 14:03:31 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Testing ScavTrap ===" << std::endl;
	
	// Test ScavTrap construction (watch the construction chaining)
	ScavTrap scav1("Guardian");
	ScavTrap scav2("Protector");
	
	std::cout << "\n--- Testing ScavTrap functions ---" << std::endl;
	
	// Test overridden attack
	scav1.attack("Intruder1");
	scav1.attack("Intruder2");
	
	// Test inherited functions
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	
	// Test special ability
	scav1.guardGate();
	
	std::cout << "\n--- Testing ScavTrap vs ClapTrap stats ---" << std::endl;
	std::cout << "ScavTrap " << scav2.getName() << " stats:" << std::endl;
	std::cout << "Hit Points: " << scav2.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << scav2.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << scav2.getAttackDamage() << std::endl;
	
	// Test edge cases for ScavTrap
	std::cout << "\n--- Testing ScavTrap edge cases ---" << std::endl;
	scav2.takeDamage(100);  // Destroy scav2
	scav2.guardGate();      // Should not work when destroyed
	
	// Test copy constructor
	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	ScavTrap scav3(scav1);
	scav3.attack("CopyTarget");
	
	std::cout << "\n--- Destruction will happen in reverse order ---" << std::endl;
	
	return 0;
}