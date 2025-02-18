/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:00:18 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 13:24:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _POINT_H_

# define _POINT_H_

#include "Fixed.hpp"

class	Point{
	private:
		Fixed const	_x;
		Fixed const	_y;
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point	&other);
		~Point();

		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
		Point&	operator=(const Point &other);
};

#endif