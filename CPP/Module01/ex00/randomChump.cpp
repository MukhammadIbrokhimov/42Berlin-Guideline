/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:15:53 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 13:16:45 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieClass.hpp"

void	randomChump(std::string name){
	Zombie	*new_zombie = newZombie(name);
	new_zombie->announce();
	delete new_zombie;
}