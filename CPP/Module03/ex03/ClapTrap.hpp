/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:13:15 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/22 13:39:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#include <iostream>

class ClapTrap {
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	
	public:
		// default constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap&	operator=(const ClapTrap &other);

		// destructor
		virtual ~ClapTrap();

		//getter
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		// extra member functions
		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	printAbout(void);


};