/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:03:51 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/13 20:33:41 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _HUMAN_A_H_
# define _HUMAN_A_H_
# include <iostream>
# include "Weapon.hpp"

class HumanA{
	private:
		std::string	_name;
		Weapon&	_typeOfWeapon;

	public:
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack(void);
};


#endif