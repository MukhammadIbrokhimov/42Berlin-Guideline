/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:15:50 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/11 14:12:08 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.class.hpp"
#include <iostream>

int Sample::created = 0;

Sample::Sample(void){
	std::cout << "Pressed" << std::endl;
	created += 1;
	std::cout << "Created: ["<< created << "]" << std::endl;
}

Sample::Sample(int p1, int p2, char p3) : a1(p1), b1(p2), c1(p3) {
	std::cout << "a1: " << a1 << std::endl;
	std::cout << "a1: " << b1 << std::endl;
	std::cout << "a1: " << c1 << std::endl;
}



void Sample::pressed(void){
	std::cout << "Pressed" << std::endl;
}

Sample::~Sample(void){
	std::cout << "deconstructed" <<std::endl;
	created -= 1;
	std::cout << "Deleted: ["<< created << "]" << std::endl;
}

int	main(void)
{
	Student joe("Joe", 23);
	Student *david = new Student("David", 21);
	Student *group = new Student[42];
	delete david;
	delete [] group;
}