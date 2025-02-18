/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/18 11:52:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                            Fixed Class Testing                             */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    std::cout << "=== Constructors and Assignment ===" << std::endl;
    Fixed a;                           // Default constructor
    Fixed b(10);                       // Int constructor
    Fixed c(42.42f);                   // Float constructor
    Fixed d(b);                        // Copy constructor

    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 10): " << b << std::endl;
    std::cout << "c (float 42.42f): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;
    
    a = c;  // Assignment operator
    std::cout << "After assignment, a = c: " << a << std::endl;

    std::cout << "\n=== Accessors and Conversions ===" << std::endl;
    std::cout << "Raw bits of b: " << b.getRawBits() << std::endl;
    b.setRawBits(128);
    std::cout << "After setting raw bits, b: " << b << std::endl;
    std::cout << "b as int: " << b.toInt() << std::endl;
    std::cout << "c as float: " << c.toFloat() << std::endl;

    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed sum = b + c;
    Fixed diff = c - b;
    Fixed prod = b * c;
    Fixed quot = c / b;
    
    std::cout << b << " + " << c << " = " << sum << std::endl;
    std::cout << c << " - " << b << " = " << diff << std::endl;
    std::cout << b << " * " << c << " = " << prod << std::endl;
    std::cout << c << " / " << b << " = " << quot << std::endl;

    std::cout << "\n=== Comparison Operators ===" << std::endl;
    std::cout << b << " > " << c << " : " << (b > c) << std::endl;
    std::cout << b << " < " << c << " : " << (b < c) << std::endl;
    std::cout << b << " >= " << d << " : " << (b >= d) << std::endl;
    std::cout << b << " <= " << d << " : " << (b <= d) << std::endl;
    std::cout << b << " == " << d << " : " << (b == d) << std::endl;
    std::cout << b << " != " << c << " : " << (b != c) << std::endl;

    std::cout << "\n=== Increment and Decrement Operators ===" << std::endl;
    Fixed e;
    std::cout << "e (initial): " << e << std::endl;
    std::cout << "Prefix ++e: " << ++e << std::endl;
    std::cout << "Postfix e++: " << e++ << std::endl;
    std::cout << "After e++: " << e << std::endl;

    std::cout << "Prefix --e: " << --e << std::endl;
    std::cout << "Postfix e--: " << e-- << std::endl;
    std::cout << "After e--: " << e << std::endl;

    std::cout << "\n=== Static min and max functions ===" << std::endl;
    Fixed f(5);
    Fixed g(10);
    std::cout << "min(" << f << ", " << g << ") = " << Fixed::min(f, g) << std::endl;
    std::cout << "max(" << f << ", " << g << ") = " << Fixed::max(f, g) << std::endl;

    const Fixed h(7);
    const Fixed i(7.5f);
    std::cout << "const min(" << h << ", " << i << ") = " << Fixed::min(h, i) << std::endl;
    std::cout << "const max(" << h << ", " << i << ") = " << Fixed::max(h, i) << std::endl;

    return 0;
}
