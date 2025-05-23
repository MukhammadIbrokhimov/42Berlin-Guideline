/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:04:56 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 22:47:46 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap{
	protected:
		std::string			_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_AttackDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		virtual ~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	aboutClapTrap(void);

		// setter
		void	setHitPoints(unsigned int value);
		void	setEnergyPoints(unsigned int value);
		void	setAttackDamage(unsigned int value);
		void	setName(std::string name);

		// getter

		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		std::string	getName(void) const;

};

#endif