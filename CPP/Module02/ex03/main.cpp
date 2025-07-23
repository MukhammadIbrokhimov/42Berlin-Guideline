/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:44:52 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/15 19:26:46 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	Point inside(5.0f, 5.0f);
	Point edge(5.0f, 0.0f);
	Point vertex(0.0f, 0.0f);
	Point outside(15.0f, 5.0f);

	std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
	std::cout << "Point on vertex: " << bsp(a, b, c, vertex) << std::endl;
	std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;

	return 0;
}
