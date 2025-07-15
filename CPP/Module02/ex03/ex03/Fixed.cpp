/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:22:27 by muxammad          #+#    #+#             */
/*   Updated: 2025/07/15 19:30:46 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

// Default constructor
Fixed::Fixed() :fixedPoint(0) {
}

// Int constructor
Fixed::Fixed(const int value): fixedPoint(value << fractional_bits){
}


// Float constructor
Fixed::Fixed(const float value)
	: fixedPoint(roundf(value * (1 << fractional_bits))) {
};

// Copy constructor
Fixed::Fixed(const Fixed& other):fixedPoint(other.fixedPoint) {
}

// Copy assignment operator
Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->fixedPoint = other.fixedPoint;
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
}

// Getters and setters
int	Fixed::getRawBits(void) const {
	return (fixedPoint);
}

void	Fixed::setRawBits(const int raw) {
	fixedPoint = raw;
}

// Conversion
float	Fixed::toFloat(void) const {
	return (static_cast<float>(fixedPoint) / (1 << fractional_bits));
}

int	Fixed::toInt(void) const {
	return (fixedPoint >> fractional_bits);
}

// Output stream operator overload (non-member)
std::ostream&	operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}

// overloading comparison operators
bool	Fixed::operator>(const Fixed& other) const {
	return fixedPoint > other.fixedPoint;
}

bool	Fixed::operator<(const Fixed& other) const {
	return fixedPoint < other.fixedPoint;
}

bool	Fixed::operator>=(const Fixed& other) const {
	return fixedPoint >= other.fixedPoint;
}

bool	Fixed::operator<=(const Fixed& other) const {
	return fixedPoint <= other.fixedPoint;
}

bool	Fixed::operator==(const Fixed& other) const {
	return fixedPoint == other.fixedPoint;
}

bool	Fixed::operator!=(const Fixed& other) const {
	return fixedPoint != other.fixedPoint;
}

// overloading aithmetic operators

Fixed	Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment/decrement

Fixed&	Fixed::operator++(){
	++fixedPoint;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed temp(*this);
	++fixedPoint;
	return temp;
}

Fixed&	Fixed::operator--(){
	--fixedPoint;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed temp(*this);
	--fixedPoint;
	return temp;
}

// Min/max functions

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a > b) ? b : a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a > b) ? b : a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}