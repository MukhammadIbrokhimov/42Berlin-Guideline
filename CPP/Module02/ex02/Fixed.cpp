/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/17 18:54:50 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fixedBits = 8;

Fixed::Fixed( void ): _value(0){}

Fixed::Fixed( const int value ): _value(value << _fixedBits ){}

Fixed::Fixed( const float value ): _value(roundf(value * (1 << _fixedBits))) {}

Fixed::~Fixed() {};

Fixed::Fixed( const Fixed &other ){
	_value = other._value;
}

Fixed&	Fixed::operator=( const Fixed &other ){
	if (this != &other){
		this->_value = other._value;
	}
	return *this;
}

int	Fixed::getRawBits( void ) const {
	return _value;
}

int	Fixed::toInt( void ) const{
	return _value >> _fixedBits;
}

float	Fixed::toFloat( void ) const{
	return static_cast<float>(_value) / (1 << _fixedBits);
}

void	Fixed::setRawBits( int const raw ){
	_value = raw;
}

// operation overloads
std::ostream&	operator<<(std::ostream &os, const Fixed &other){
	os << other.toFloat();
	return os;
}

// comparison operators
bool	Fixed::operator>(const Fixed &other) const{
	return _value > other._value;
}

bool	Fixed::operator>=(const Fixed &other) const{
	return _value > other._value;
}

bool	Fixed::operator<(const Fixed &other) const{
	return _value > other._value;
}

bool	Fixed::operator<=(const Fixed &other) const{
	return _value > other._value;
}

bool	Fixed::operator==(const Fixed &other) const{
	return _value > other._value;
}

bool	Fixed::operator!=(const Fixed &other) const{
	return _value > other._value;
}

// arithmetic operators

Fixed	Fixed::operator+(const Fixed &other) const{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const{
	return Fixed(this->toFloat() / other.toFloat());
}