/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:04:32 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 21:21:49 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "Creating FragTrap..." << std::endl;
    FragTrap frag("Fraggy");

    std::cout << "\nTesting attacks:" << std::endl;
    frag.attack("Enemy1");
    frag.attack("Enemy2");
    
    std::cout << "\nTesting high fives:" << std::endl;
    frag.highFivesGuys();

    std::cout << "\nTesting damage and repairs:" << std::endl;
    frag.takeDamage(30);
    frag.beRepaired(20);

    std::cout << "\nDestroying FragTrap..." << std::endl;
    return 0;
}
