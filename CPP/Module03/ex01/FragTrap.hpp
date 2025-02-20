/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:47:25 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/20 19:03:14 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _FRAG_TRAP_H_

# define _FRAG_TRAP_H_

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
public:
	FragTrap();
	~FragTrap();

	void	highFiveGuys(void);
};

#endif