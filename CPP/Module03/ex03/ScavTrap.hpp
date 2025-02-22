/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:47:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/22 22:29:57 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _SCAV_TRAP_H_

# define _SCAV_TRAP_H_

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
public:
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap(const ScavTrap &other);
	ScavTrap&	operator=(const ScavTrap &other);

	void	guardGate(void);
};

#endif