/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:47:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/21 20:59:59 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _SCAV_TRAP_H_

# define _SCAV_TRAP_H_

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
public:
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap(const ScavTrap &other);
	ScavTrap&	operator=(const ScavTrap &other);

	void	guardGate(void);
};

#endif