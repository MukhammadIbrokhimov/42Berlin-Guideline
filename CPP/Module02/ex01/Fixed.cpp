/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:22:27 by muxammad          #+#    #+#             */
/*   Updated: 2025/07/15 17:56:42 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

// Default constructor
Fixed::Fixed() :fixedPoint(0) {
	std::cout << 
		"Default constructor called"
	<< std::endl;
}

// Int constructor
Fixed::Fixed(const int value): fixedPoint(value << fractional_bits){
	std::cout << 
		"Int constructor called"
	<< std::endl;
}


// Float constructor
Fixed::Fixed(const float value)
	: fixedPoint(roundf(value * (1 << fractional_bits))) {
	std::cout << 
		"float constructor called"
	<< std::endl;
};

// Copy constructor
Fixed::Fixed(const Fixed& other):fixedPoint(other.fixedPoint) {
	std::cout << 
		"Copy constructor called"
	<< std::endl;
}

// Copy assignment operator
Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout <<
		"Copy assignment operator called"
	<< std::endl;
	if (this != &other) {
		this->fixedPoint = other.fixedPoint;
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << 
		"Destructor called"
	<< std::endl;
}

// Getters and setters
int	Fixed::getRawBits(void) const {
	std::cout <<
		"getRawBits member function called"
	<< std::endl;
	return (fixedPoint);
}

void	Fixed::setRawBits(const int raw) {
	std::cout <<
		"setRawBits member function called"
	<< std::endl;
	fixedPoint = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(fixedPoint) / (1 << fractional_bits));
}

int	Fixed::toInt(void) const {
	return (fixedPoint >> fractional_bits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &value){
	out << value.toFloat();
	return (out);
}