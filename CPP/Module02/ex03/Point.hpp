/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:10:45 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/15 19:27:14 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"
#include <iostream>

class Point{
	private:
		const Fixed x;	
		const Fixed y;
	public:
		Point(); // default constructor initialize to 0
		Point(const float _x, const float _y);
		Point(const Point& other);
		Point& operator=(const Point& other); 
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);