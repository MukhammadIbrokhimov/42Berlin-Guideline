/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:22:27 by muxammad          #+#    #+#             */
/*   Updated: 2025/07/15 17:29:31 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() :fixedPoint(0) {
	std::cout << 
		"Default constructor called"
	<< std::endl;
}

Fixed::Fixed(const Fixed& other):fixedPoint(other.fixedPoint) {
	std::cout << 
		"Copy constructor called"
	<< std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout <<
		"Copy assignment operator called"
	<< std::endl;
	if (this != &other) {
		this->fixedPoint = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << 
		"Destructor called"
	<< std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout <<
		"getRawBits member function called"
	<< std::endl;
	return (fixedPoint);
}

void	Fixed::setRawBits(const int raw){
	std::cout <<
		"setRawBits member function called"
	<< std::endl;
	fixedPoint = raw;
}