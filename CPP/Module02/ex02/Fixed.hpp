/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:35 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 11:49:55 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _FIXED_H_
# define _FIXED_H_

# include <iostream>
# include <cmath>

class Fixed{
	private:
		static const int	_fixedBits;
		int					_value;
	public:
		Fixed( void );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed();

		Fixed( const Fixed &other );

		Fixed&	operator=( const Fixed &other );

		int		getRawBits( void ) const;
		int		toInt( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		
		// comparison operators
		bool	operator>( const Fixed &other ) const;
		bool	operator<( const Fixed &other ) const;
		bool	operator>=( const Fixed &other ) const;
		bool	operator<=( const Fixed &other ) const;
		bool	operator==( const Fixed &other ) const;
		bool	operator!=( const Fixed &other ) const;

		// arithmetic operators
		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&	min(Fixed& fValue, Fixed& sValue);
		static const Fixed&	min(const Fixed& fValue, const Fixed& sValue);
		static Fixed&	max(Fixed& fValue, Fixed& sValue);
		static const Fixed&	max(const Fixed& fValue, const Fixed& sValue);

		friend std::ostream& operator<<( std::ostream &os, const Fixed &other );
};

#endif