/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:36 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 15:30:44 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== DIAMOND INHERITANCE TESTING ===" << std::endl;
	
	std::cout << "\n--- Construction Phase (Watch the Order!) ---" << std::endl;
	DiamondTrap diamond("Hybrid");
	
	std::cout << "\n--- Testing Identity Crisis ---" << std::endl;
	diamond.whoAmI();
	
	std::cout << "\n--- Testing Attribute Inheritance ---" << std::endl;
	std::cout << "DiamondTrap stats (should be mixed from parents):" << std::endl;
	std::cout << "Hit Points: " << diamond.getHitPoints() << " (should be 100 - from FragTrap)" << std::endl;
	std::cout << "Energy Points: " << diamond.getEnergyPoints() << " (should be 50 - from ScavTrap)" << std::endl;
	std::cout << "Attack Damage: " << diamond.getAttackDamage() << " (should be 30 - from FragTrap)" << std::endl;
	
	std::cout << "\n--- Testing Method Inheritance ---" << std::endl;
	// Attack should come from ScavTrap (as specified)
	diamond.attack("TestEnemy");
	
	// Should have both special abilities
	diamond.guardGate();      // From ScavTrap
	diamond.highFivesGuys();  // From FragTrap
	diamond.whoAmI();         // DiamondTrap's own
	
	std::cout << "\n--- Testing Name Shadowing ---" << std::endl;
	std::cout << "DiamondTrap name: " << diamond.getDiamondName() << std::endl;
	std::cout << "ClapTrap name: " << diamond.getClapTrapName() << std::endl;
	
	std::cout << "\n--- Testing Combat Scenario ---" << std::endl;
	diamond.takeDamage(25);   // Should work (inherited from ClapTrap)
	diamond.beRepaired(10);   // Should work (inherited from ClapTrap)
	diamond.attack("Enemy2"); // Should use ScavTrap's attack
	diamond.whoAmI();
	
	std::cout << "\n--- Testing Multiple DiamondTraps ---" << std::endl;
	{
		DiamondTrap d1("Alpha");
		DiamondTrap d2("Beta");
		
		d1.whoAmI();
		d2.whoAmI();
		
		// Test interaction
		d1.attack("Beta");
		d2.guardGate();
		d1.highFivesGuys();
		
		std::cout << "Multiple diamonds created successfully!" << std::endl;
		// Destruction will happen here
	}
	
	std::cout << "\n--- Testing Copy and Assignment ---" << std::endl;
	DiamondTrap original("Original");
	original.takeDamage(20);
	
	DiamondTrap copy(original);  // Copy constructor
	copy.whoAmI();
	
	DiamondTrap assigned("Assigned");
	assigned = original;  // Assignment operator
	assigned.whoAmI();
	
	std::cout << "\n--- Testing Edge Cases ---" << std::endl;
	DiamondTrap destroyed("Doomed");
	destroyed.takeDamage(100);  // Destroy it
	destroyed.whoAmI();         // Should handle gracefully
	destroyed.guardGate();      // Should handle gracefully
	destroyed.attack("Target"); // Should not work
	
	std::cout << "\n--- Testing Polymorphism ---" << std::endl;
	// DiamondTrap can be treated as any of its base classes
	ClapTrap* asClap = &diamond;
	//ScavTrap* asScav = &diamond;
	//FragTrap* asFrag = &diamond;
	
	asClap->attack("PolyTarget1");  // Should call ScavTrap::attack due to override
	// asScav->guardGate();         // ScavTrap specific
	// asFrag->highFivesGuys();     // FragTrap specific
	
	std::cout << "\n--- Stress Testing All Abilities ---" << std::endl;
	DiamondTrap ultimate("Ultimate");
	
	// Use some energy
	for (int i = 0; i < 3; i++) {
		ultimate.attack("StressEnemy");
		ultimate.beRepaired(5);
	}
	
	// Use all special abilities
	ultimate.guardGate();
	ultimate.highFivesGuys();
	ultimate.whoAmI();
	
	std::cout << "\nFinal stats:" << std::endl;
	std::cout << "Energy: " << ultimate.getEnergyPoints() << std::endl;
	std::cout << "HP: " << ultimate.getHitPoints() << std::endl;
	
	std::cout << "\n--- Destruction Phase (Watch Reverse Order!) ---" << std::endl;
	
	return 0;
}