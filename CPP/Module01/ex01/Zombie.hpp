/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:30:04 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 13:51:09 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _ZOMBIE_H_

# define _ZOMBIE_H_

# include <string.h>
# include <iostream>

class Zombie{
	private:
		std::string _name;
	public:
		Zombie(void);
		~Zombie();
		void	announce(void);
		void setName(std::string name);
};


Zombie	*zombieHorde(int N, std::string name);

#endif