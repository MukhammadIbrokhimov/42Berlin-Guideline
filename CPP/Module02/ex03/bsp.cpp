/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:25:03 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/15 19:26:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c) {
	Fixed result = (a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY())) / Fixed(2);
	return result < Fixed(0) ? result * Fixed(-1) : result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed total = area(a, b, c);
	Fixed p1 = area(point, b, c);
	Fixed p2 = area(a, point, c);
	Fixed p3 = area(a, b, point);

	// Must be strictly inside: no edge, no vertex, no zero sub-area
	if (p1 == Fixed(0) || p2 == Fixed(0) || p3 == Fixed(0))
		return false;

	return (p1 + p2 + p3 == total);
}