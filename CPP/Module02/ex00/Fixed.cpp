/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:17:06 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/15 18:37:34 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _fixedNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Deconstructor called" << std::endl;

}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	_fixedNumber = other._fixedNumber;
}

Fixed&	Fixed::operator=( const Fixed &other ){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		_fixedNumber = other._fixedNumber;
	}
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedNumber;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedNumber = raw;
}

