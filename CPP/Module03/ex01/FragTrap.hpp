/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:47:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/19 18:51:04 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _FRAG_TRAP_H_

# define _FRAG_TRAP_H_

# include "ClapTrap.hpp"

class FragTrap: ClapTrap{
public:
	FragTrap(/* args */);
	~FragTrap();

	void	highFiveGuys(void);
};

#endif