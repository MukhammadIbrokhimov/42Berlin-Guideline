/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:00:15 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 13:24:34 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(), _y(){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(const Point &other): _x(other._x), _y(other._y){}

Point::~Point() {}

Point&	Point::operator=(const Point &other){
	return *this;
}

Fixed const	Point::getX(void) const{
	return _x;
}

Fixed const	Point::getY(void) const{
	return _y;
}