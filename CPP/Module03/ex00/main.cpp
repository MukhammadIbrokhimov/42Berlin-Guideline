/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:56:40 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/21 19:48:07 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main() {
	// Creating ClapTrap instances
	ClapTrap person1("Attacker");
	ClapTrap person2("Defender");

	std::cout << "\n--- Initial Status ---" << std::endl;
	person1.aboutClapTrap();
	person2.aboutClapTrap();

	std::cout << "\n--- Attacking ---" << std::endl;
	person1.attack("Enemy");
	person2.attack("Attacker");

	std::cout << "\n--- Taking Damage ---" << std::endl;
	person1.takeDamage(5);
	person2.takeDamage(10);  // Should destroy person2

	std::cout << "\n--- Trying to Repair ---" << std::endl;
	person1.beRepaired(3);  // Should increase HP
	person2.beRepaired(5);  // Should fail since person2 is destroyed

	std::cout << "\n--- Final Status ---" << std::endl;
	person1.aboutClapTrap();
	person2.aboutClapTrap();

	return 0;
}
