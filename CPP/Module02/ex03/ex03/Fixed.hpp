/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:22:31 by muxammad          #+#    #+#             */
/*   Updated: 2025/07/15 18:50:04 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include "iostream"

class Fixed {
	private:
		int	fixedPoint;
		const static int fractional_bits;
	
	public:
		// Orthodox Canonical Form
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		// Getters and setters
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		
		// Conversion
		float	toFloat(void) const;
		int		toInt(void) const;

		//comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		
		//arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;


		// Increment/decrement
		Fixed& operator++();     // Pre-increment
		Fixed operator++(int);   // Post-increment
		Fixed& operator--();     // Pre-decrement
		Fixed operator--(int);   // Post-decrement
		
		// Min/max functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
};

// Output stream operator overload (non-member)
std::ostream&	operator<<(std::ostream &out, const Fixed &value);
