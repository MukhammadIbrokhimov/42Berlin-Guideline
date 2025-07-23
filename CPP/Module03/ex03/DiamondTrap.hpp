/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:23:50 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 15:29:19 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	public:
		DiamondTrap();
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);

		~DiamondTrap();

		using ScavTrap::attack;
		void attack(const std::string& target);
		void whoAmI();
		// Getters to access the shadowed name
		std::string getDiamondName() const;
		std::string getClapTrapName() const;
};