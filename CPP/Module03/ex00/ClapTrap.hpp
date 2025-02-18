/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:04:56 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 15:02:29 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

# ifndef _CLAP_TRAP_H_

# define _CLAP_TRAP_H_

# include <iostream>
# include <string.h>

class ClapTrap{
	private:
		std::string			_name;
		static unsigned int	_hitPoints;
		static unsigned int	_energyPoints;
		static unsigned int	_AttackDamage;
	
	public:
		ClapTrap(std::string name);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	aboutClapTrap(void){
			std::cout << "Hitpoints: " << _hitPoints << std::endl;
			std::cout << "_energyPoints: " << _energyPoints << std::endl;
			std::cout << "AttackDamage: " << _AttackDamage << std::endl;
		}

};

#endif