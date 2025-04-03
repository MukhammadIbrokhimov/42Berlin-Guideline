/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:54:19 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 23:00:30 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _DIAMOND_TRAP_HPP_
#define _DIAMON_TRAP_HPP_

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
	private:
		std::string _name;
	public:
		DiamondTrap(std::string name);
		~DiamondTrap();

		DiamondTrap(const DiamondTrap &other);
		DiamondTrap& operator=(const DiamondTrap &other);

		using ScavTrap::attack;
		void	whoAmi();
};


#endif