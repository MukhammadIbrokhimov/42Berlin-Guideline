/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:06:36 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 14:19:34 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Testing All Three Classes (Ex00, Ex01, Ex02) ===" << std::endl;
	
	// Test construction chaining for all classes
	std::cout << "\n--- Construction Phase ---" << std::endl;
	ClapTrap clap("BasicBot");
	ScavTrap scav("Guardian");
	FragTrap frag("Destroyer");
	
	std::cout << "\n--- Testing FragTrap Stats ---" << std::endl;
	std::cout << "FragTrap " << frag.getName() << " stats:" << std::endl;
	std::cout << "Hit Points: " << frag.getHitPoints() << " (should be 100)" << std::endl;
	std::cout << "Energy Points: " << frag.getEnergyPoints() << " (should be 100)" << std::endl;
	std::cout << "Attack Damage: " << frag.getAttackDamage() << " (should be 30)" << std::endl;
	
	std::cout << "\n--- Comparing Attack Messages ---" << std::endl;
	clap.attack("Enemy");
	scav.attack("Enemy");
	frag.attack("Enemy");
	
	std::cout << "\n--- Testing Special Abilities ---" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	
	std::cout << "\n--- Testing FragTrap Durability ---" << std::endl;
	// FragTrap should be more durable than others
	frag.takeDamage(50);
	frag.beRepaired(25);
	frag.attack("Tough Enemy");
	frag.highFivesGuys();
	
	std::cout << "\n--- Testing Energy Consumption ---" << std::endl;
	// FragTrap has 100 energy, let's use some of it
	for (int i = 0; i < 5; i++) {
		frag.attack("Multiple Enemies");
	}
	for (int i = 0; i < 3; i++) {
		frag.beRepaired(10);
	}
	std::cout << "Energy remaining: " << frag.getEnergyPoints() << " (should be 92)" << std::endl;
	
	std::cout << "\n--- Testing Edge Cases for FragTrap ---" << std::endl;
	// Test when FragTrap is destroyed
	FragTrap weakFrag("WeakOne");
	weakFrag.takeDamage(100);  // Destroy it
	weakFrag.highFivesGuys();  // Should handle gracefully
	weakFrag.attack("Target");  // Should not work
	
	std::cout << "\n--- Testing Copy Constructor and Assignment ---" << std::endl;
	FragTrap original("Original");
	original.takeDamage(30);
	
	FragTrap copy(original);  // Copy constructor
	copy.highFivesGuys();
	
	FragTrap assigned("Assigned");
	assigned = original;  // Assignment operator
	assigned.attack("AssignmentTarget");
	
	std::cout << "\n--- Testing Polymorphic Behavior ---" << std::endl;
	// All three types attacking the same target
	ClapTrap* robots[3] = {&clap, &scav, &frag};
	for (int i = 0; i < 3; i++) {
		robots[i]->attack("PolymorphicTarget");
	}
	
	std::cout << "\n--- Stress Testing FragTrap ---" << std::endl;
	FragTrap stress("StressTest");
	
	// Use up energy gradually
	for (int i = 0; i < 20 && stress.getEnergyPoints() > 0; i++) {
		if (i % 2 == 0)
			stress.attack("StressEnemy");
		else
			stress.beRepaired(5);
	}
	
	stress.highFivesGuys();
	std::cout << "Final energy: " << stress.getEnergyPoints() << std::endl;
	std::cout << "Final hit points: " << stress.getHitPoints() << std::endl;
	
	std::cout << "\n--- Testing Multiple FragTraps ---" << std::endl;
	{
		FragTrap team1("Alpha");
		FragTrap team2("Beta");
		FragTrap team3("Gamma");
		
		team1.highFivesGuys();
		team2.highFivesGuys();
		team3.highFivesGuys();
		
		std::cout << "Team formation complete!" << std::endl;
		// Destructors will be called here in reverse order
	}
	
	std::cout << "\n--- Final Comparison Test ---" << std::endl;
	std::cout << "ClapTrap damage: " << clap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap damage: " << scav.getAttackDamage() << std::endl;
	std::cout << "FragTrap damage: " << frag.getAttackDamage() << std::endl;
	
	std::cout << "\n--- Destruction Phase (watch the reverse order) ---" << std::endl;
	
	return 0;
}