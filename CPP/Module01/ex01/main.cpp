/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:17:32 by hta-rezi2         #+#    #+#             */
/*   Updated: 2025/07/06 05:22:04 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    int number = 10;
    Zombie *horde = zombieHorde(number, "Horde");
    for(int i = 0; i < number; i++){
        std::cout << "Index[" << i << "]";
        horde[i].announce();
    }
    delete[] horde;
}