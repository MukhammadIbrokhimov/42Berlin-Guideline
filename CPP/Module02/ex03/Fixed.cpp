/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 11:49:56 by mukibrok         ###   ########.fr       */
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

// prefix and postfix incrementing
Fixed&	Fixed::operator++(void){
	this->_value += 1;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	tmp(*this);
	this->_value += 1;
	return tmp;
}

Fixed&	Fixed::operator--(void){
	this->_value -= 1;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	this->_value -= 1;
	return tmp;
}

// Min and Max overloaded functions
Fixed&	Fixed::min(Fixed& fValue, Fixed& sValue){
	return(fValue.toFloat() < sValue.toFloat()) ? fValue : sValue;
}

const Fixed&	Fixed::min(const Fixed& fValue, const Fixed& sValue){
	return(fValue.toFloat() < sValue.toFloat()) ? fValue : sValue;
}

Fixed&	Fixed::max(Fixed& fValue, Fixed& sValue){
	return(fValue.toFloat() > sValue.toFloat()) ? fValue : sValue;
}

const Fixed&	Fixed::max(const Fixed& fValue, const Fixed& sValue){
	return (fValue.toFloat() > sValue.toFloat()) ? fValue : sValue;
}
