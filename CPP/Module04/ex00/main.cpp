/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:29:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 17:22:51 by mukibrok         ###   ########.fr       */
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
	std::cout << "==============================================================\n";
	std::cout << "checking with subject main functions\n";
	Animal	*meta = new Animal();
	Animal	*j = new Dog();
	Animal	*i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
}