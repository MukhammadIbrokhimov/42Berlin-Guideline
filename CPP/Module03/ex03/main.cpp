/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:58:57 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 14:52:40 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "\nCreating DiamondTrap...\n";
    DiamondTrap diamond("Diamondy");

    std::cout << "\nTesting attack:\n";
    diamond.attack("Enemy");

    std::cout << "\nTesting high five:\n";
    diamond.highFivesGuys();

    std::cout << "\nTesting whoAmI:\n";
    diamond.whoAmi();

    std::cout << "\nDestroying DiamondTrap...\n";

	std::cout << "testing copy operator\n";
	DiamondTrap copied(diamond);
	DiamondTrap tempoo = copied;

    return 0;
}
