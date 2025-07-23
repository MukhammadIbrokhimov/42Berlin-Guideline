/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:36 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 13:57:45 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	
	// Test ClapTrap construction
	ClapTrap clap1("Clappy");
	ClapTrap clap2("Trappy");
	
	std::cout << "\n--- Testing ClapTrap basic functions ---" << std::endl;
	
	// Test attack
	clap1.attack("Enemy1");
	clap1.attack("Enemy2");
	
	// Test taking damage
	clap1.takeDamage(5);
	clap1.takeDamage(3);
	
	// Test repair
	clap1.beRepaired(4);
	
	// Test edge cases - no energy
	std::cout << "\n--- Testing energy depletion ---" << std::endl;
	for (int i = 0; i < 10; i++) {
		clap2.attack("Target");
	}
	// Should not be able to attack or repair now
	clap2.attack("Target");
	clap2.beRepaired(1);
	
	// Test edge cases - no hit points
	std::cout << "\n--- Testing hit points depletion ---" << std::endl;
	clap1.takeDamage(20);  // Should destroy clap1
	clap1.attack("Target");  // Should not work
	clap1.beRepaired(5);     // Should not work
	
	return 0;
}
