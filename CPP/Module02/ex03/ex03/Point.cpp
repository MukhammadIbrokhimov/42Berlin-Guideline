/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:15:47 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/15 19:31:06 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(const float _x, const float _y): x(_x), y(_y) {
}

Point::Point(const Point& other): x(other.x), y(other.y) {};

Point&	Point::operator=(const Point& other){
// Since _x and _y are const, we cannot assign them after construction.
// So we return *this without modifying anything.
	if (this != &other) {
		return *this;
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return x; }

Fixed Point::getY() const { return y; }