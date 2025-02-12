/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:30:07 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 14:14:07 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	if (N < 1){
		std::cout << "Not possible to create a Zombie !!!" << std::endl;
		return (NULL);
	}
	Zombie	*ZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		ZombieHorde[i].setName(name);
		ZombieHorde[i].announce();
	}
	return ZombieHorde;
}