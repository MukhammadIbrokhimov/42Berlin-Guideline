/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 04:20:02 by hta-rezi2         #+#    #+#             */
/*   Updated: 2025/07/06 05:07:28 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++){
        new(&zombie[i]) Zombie(name);
    }
    return zombie;
}