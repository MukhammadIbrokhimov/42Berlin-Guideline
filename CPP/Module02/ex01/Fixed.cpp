/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:05:00 by muxammad          #+#    #+#             */
/*   Updated: 2025/02/16 18:37:24 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ): _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const int value ): _value(value){
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed( const float value ): _value(value){
	std::cout << "float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other ){
	std::cout << "copy constructor called" << std::endl;
	_value = other._value;
}

Fixed::~Fixed(){
	std::cout << "Default deconstructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const &other ){
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other){
		this->_value = other._value;
	}
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}