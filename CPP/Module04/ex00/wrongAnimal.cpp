/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:12:10 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 17:13:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

// wrongAnimal class settings

wrongAnimal::wrongAnimal(): type("wrongAnimal"){
	std::cout << "wrongAnimal constructor has been called\n";
}

wrongAnimal::~wrongAnimal() {
	std::cout << "wrongAnimal Destructor has been called!\n";
}

wrongAnimal::wrongAnimal( const wrongAnimal &other){
	*this = other;
	std::cout << "wrongAnimal Copy constructor has been called!\n";
}

wrongAnimal& wrongAnimal::operator=( const wrongAnimal &other){
	if (this != &other){
		this->type = other.type;
	}
	std::cout << "wrongAnimal copy operator has been called!\n";
	return *this;
}

void	wrongAnimal::makeSound(void){
	std::cout << "Here will be sound of the wrongAnimal\n";
}

std::string wrongAnimal::getType(void){
	std::cout << "wrongAnimal getter has been called\n";
	return (type);
}

// wrongDog class settings

wrongDog::wrongDog() {
	std::cout << "wrongDog Constructor has been called!\n";
	type = "wrongDog";
}

wrongDog::~wrongDog() {
	std::cout << "wrongDog Destructor has been called!\n";
}

void wrongDog::makeSound(void) {
	std::cout << "wrongDog:: Woof! Woof!\n";
}

wrongDog::wrongDog(const wrongDog &wrongDog): wrongAnimal(wrongDog){
	//this->type = wrongDog.type; // other way
	std::cout << "wrongDog Copy Constructor has been called!\n";
}

wrongDog& wrongDog::operator=(const wrongDog &wrongDog){
	if (this != &wrongDog){
		//this->type = wrongDog.type; other way
		wrongAnimal::operator=(wrongDog);
	}
	std::cout << "wrongDog operator has been called!\n";
	return *this;
}

// wrongCat class settings

void wrongCat::makeSound(void) {
	std::cout << "wrongCat:: Myaow! Myaow!\n";
}

wrongCat::wrongCat(){
	std::cout << "wrongCat Constructor has been called!\n";
	type = "wrongCat";
}

wrongCat::~wrongCat(){
	std::cout << "wrongCat Destructor has been called!\n";
}

wrongCat::wrongCat(const wrongCat &wrongCat): wrongAnimal(wrongCat){
	//this->type = wrongCat.type;
	std::cout << "wrongCat Copy Constructor has been called!\n";
}

wrongCat& wrongCat::operator=(const wrongCat &wrongCat){
	if (this != &wrongCat){
		type = wrongCat.type;
	}
	std::cout << "wrongCat operator has been called!\n";
	return *this;
}