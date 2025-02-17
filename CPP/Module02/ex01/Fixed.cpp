/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:05:00 by muxammad          #+#    #+#             */
/*   Updated: 2025/02/17 15:32:01 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed( void ): _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( const int value ): _value(value << _fractBits){
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed( const float value ): _value(roundf(value * (1 << _fractBits))){
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

std::ostream& operator<<(std::ostream &os, const Fixed &other){
	os << other.toFloat();
	return os;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast <float>(_value) / (1 << _fractBits);
}

int		Fixed::toInt( void ) const{
	return _value >> _fractBits;
}
