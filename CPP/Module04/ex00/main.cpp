/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:29:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 17:19:00 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"
#include "animal.hpp"

int main(void){
	Animal *animal = new Dog();
	Animal *animal1 = new Cat();

	std::cout << "checking for virtual functions\n";

	std::cout << "Animal type checking\n";
	std::cout << "Animal type object 1 " << animal->getType() << std::endl;
	std::cout << "Animal type object 2 " << animal1->getType() << std::endl;

	std::cout << "Animal sound checking\n";

	animal->makeSound();
	animal1->makeSound();

	delete animal;
	delete animal1;

	std::cout << "==============================================================\n";
	std::cout << "checking for non-virtual functions\n";

	wrongAnimal *WrongAnimal = new wrongDog();
	wrongAnimal *WrongAnimal1 = new wrongCat();

	std::cout << "checking for non - virtual functions\n";

	std::cout << "Animal type checking\n";
	std::cout << "Animal type object 1 " << WrongAnimal->getType() << std::endl;
	std::cout << "Animal type object 2 " << WrongAnimal1->getType() << std::endl;

	std::cout << "Animal sound checking\n";

	WrongAnimal->makeSound();
	WrongAnimal1->makeSound();
	delete WrongAnimal;
	delete WrongAnimal1;
}