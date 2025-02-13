/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:02:59 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/13 20:41:03 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _HUMAN_B_H_
# define _HUMAN_B_H_
# include "HumanA.hpp"
# include <iostream>

class	HumanB{
	private:
		std::string	_name;
		Weapon		*_typeOfWeapon;
	public:
		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon &weapon);
		void	attack(void);
};

#endif