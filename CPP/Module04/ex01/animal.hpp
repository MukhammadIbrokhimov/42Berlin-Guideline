/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:29:34 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 18:35:37 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP_
# define ANIMAL_HPP_

# include <iostream>
# include <string.h>
# include "brain.hpp"

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal( const Animal &other );
		virtual ~Animal();

		Animal&	operator=(const Animal &other);
		virtual void makeSound( void );
		std::string getType(void);
};
class Dog: public Animal{
	private:
		Brain	*brain;
	public:
	
		Dog();
		~Dog();

		Dog( const Dog &dog );
		Dog& operator=( const Dog &dog );
		void makeSound( void );
		Brain* getBrain(void);
};

class Cat: public Animal{
	private:
		Brain	*brain;
	public:
		Cat();
		~Cat();
		void makeSound( void );
		Cat(const Cat &cat);
		Cat& operator=( const Cat &cat );
		Brain* getBrain(void);
};

#endif