/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:06:52 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 19:14:39 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _A_MATERIA_HPP_
#define _A_MATERIA_HPP_

# include <iostream>
# include <string.h>

class AMateria{
	protected:
		std::string const _type;
	
	public:
		AMateria(std::string const &type);
		~AMateria();
		AMateria(const AMateria &other);
		AMateria& operator=(const AMateria &other);

		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class ICharacter{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif