/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muxammad <muxammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:04:56 by muxammad          #+#    #+#             */
/*   Updated: 2025/02/16 18:35:47 by muxammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _FIXED_H_

# define _FIXED_H_

# include <iostream>
# include <cmath>

class Fixed
{
private:
	static const int	_fractBits;
	int					_value;
public:
	Fixed ( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( const Fixed& other );
	~Fixed();

	Fixed&	operator=( Fixed const &other );
	int	getRawBits( void ) const;
	void setRawBits( int const raw);
};

#endif