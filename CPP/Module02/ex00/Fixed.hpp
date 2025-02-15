/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:17:10 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/15 18:20:36 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _FIXED_H_

# define _FIXED_H_

# include <iostream>
# include <string>

class Fixed{
	private:
		static const int	_fractBits;
		int					_fixedNumber;

		public:
		Fixed( void );
		~Fixed();
		Fixed( const Fixed& other );

		Fixed	&operator=( const Fixed &other );
		int		getRawBits( void ) const;
		void	setRawBits( int  const raw );
};

#endif