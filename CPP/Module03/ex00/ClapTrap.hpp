/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:04:56 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/21 20:41:54 by mukibrok         ###   ########.fr       */
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
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	
	public:
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap& operator=(const ClapTrap &other);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	aboutClapTrap(void);

};

#endif