/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:12:32 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 17:19:13 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _WRONG_ANIMAL_HPP_
#define _WROND_ANIMAL_HPP_

#include <iostream>

#include <string.h>

class wrongAnimal{
	protected:
		std::string type;
	public:
		wrongAnimal();
		wrongAnimal( const wrongAnimal &other );
		~wrongAnimal();

		wrongAnimal&	operator=(const wrongAnimal &other);
		void makeSound( void );
		std::string getType(void);
};
class wrongDog: public wrongAnimal{
	public:
	
		wrongDog();
		~wrongDog();

		wrongDog( const wrongDog &wrongDog );
		wrongDog& operator=( const wrongDog &wrongDog );
		void makeSound( void );
};

class wrongCat: public wrongAnimal{
	public:
		wrongCat();
		~wrongCat();
		void makeSound( void );
		wrongCat(const wrongCat &wrongCat);
		wrongCat& operator=( const wrongCat &wrongCat );
};


#endif