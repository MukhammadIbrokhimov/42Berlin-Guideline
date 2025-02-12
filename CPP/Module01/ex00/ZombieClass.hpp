/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:45:17 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 13:18:32 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_CLASS_F_

# define _ZOMBIE_CLASS_F_
# include <iostream>

class	Zombie{
	private:
		std::string _name;
	public:
		// constructor
		Zombie(void);
		Zombie(std::string name);
		// destructor
		~Zombie(void);
		// getter
		std::string GetName(void);

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif