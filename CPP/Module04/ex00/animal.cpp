/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:29:37 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 17:11:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

// animal class settings

Animal::Animal(): type("Animal"){
	std::cout << "Animal constructor has been called\n";
}

Animal::~Animal() {
	std::cout << "Animal Destructor has been called!\n";
}

Animal::Animal( const Animal &other){
	*this = other;
	std::cout << "Animal Copy constructor has been called!\n";
}

Animal& Animal::operator=( const Animal &other){
	if (this != &other){
		this->type = other.type;
	}
	std::cout << "Animal copy operator has been called!\n";
	return *this;
}

void	Animal::makeSound(void){
	std::cout << "Here will be sound of the animal\n";
}

std::string Animal::getType(void){
	std::cout << "Animal getter has been called\n";
	return (type);
}

// Dog class settings

Dog::Dog() {
	std::cout << "Dog Constructor has been called!\n";
	type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog Destructor has been called!\n";
}

void Dog::makeSound(void) {
	std::cout << "Dog:: Woof! Woof!\n";
}

Dog::Dog(const Dog &dog): Animal(dog){
	//this->type = dog.type; // other way
	std::cout << "Dog Copy Constructor has been called!\n";
}

Dog& Dog::operator=(const Dog &dog){
	if (this != &dog){
		//this->type = dog.type; other way
		Animal::operator=(dog);
	}
	std::cout << "Dog operator has been called!\n";
	return *this;
}

// Cat class settings

void Cat::makeSound(void) {
	std::cout << "Cat:: Myaow! Myaow!\n";
}

Cat::Cat(){
	std::cout << "Cat Constructor has been called!\n";
	type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat Destructor has been called!\n";
}

Cat::Cat(const Cat &cat): Animal(cat){
	std::cout << "Cat Copy Constructor has been called!\n";
}

Cat& Cat::operator=(const Cat &cat){
	if (this != &cat){
		//type = cat.type;
		Animal::operator=(cat);
	}
	std::cout << "Cat operator has been called!\n";
	return *this;
}