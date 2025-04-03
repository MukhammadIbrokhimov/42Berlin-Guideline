/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:29:02 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 18:36:53 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include <iomanip>

void print_header(const std::string& text) {
	std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n";
	std::cout << text;
	std::cout << "\n" << std::setw(50) << std::setfill('=') << "\n" << std::setfill(' ');
}

void test_brain_functionality() {
	print_header("Testing Brain functionality");
	
	// Test basic Brain operations
	Dog* dog = new Dog();
	dog->getBrain()->setIdea(0, "I need to bark at strangers");
	dog->getBrain()->setIdea(1, "Where's my bone?");
	std::cout << "Dog's ideas:\n"
			<< "0: " << dog->getBrain()->getIdea(0) << "\n"
			<< "1: " << dog->getBrain()->getIdea(1) << "\n";
	delete dog;

	Cat* cat = new Cat();
	cat->getBrain()->setIdea(0, "I need to nap in a sunbeam");
	cat->getBrain()->setIdea(99, "This is my last idea");
	std::cout << "\nCat's ideas:\n"
			<< "0: " << cat->getBrain()->getIdea(0) << "\n"
			<< "99: " << cat->getBrain()->getIdea(99) << "\n";
	delete cat;
}

void test_deep_copies() {
	print_header("Testing Deep Copies");
	
	// Test Dog copy constructor
	Dog original_dog;
	original_dog.getBrain()->setIdea(0, "Original dog idea");
	Dog copy_dog(original_dog);
	copy_dog.getBrain()->setIdea(0, "Copied dog idea");
	
	std::cout << "Dog copy results:\n"
			<< "Original: " << original_dog.getBrain()->getIdea(0) << "\n"
			<< "Copy: " << copy_dog.getBrain()->getIdea(0) << "\n\n";

	// Test Cat assignment operator
	Cat original_cat;
	original_cat.getBrain()->setIdea(42, "Original cat idea");
	Cat assigned_cat;
	assigned_cat = original_cat;
	assigned_cat.getBrain()->setIdea(42, "Assigned cat idea");
	
	std::cout << "Cat assignment results:\n"
			<< "Original: " << original_cat.getBrain()->getIdea(42) << "\n"
			<< "Assigned: " << assigned_cat.getBrain()->getIdea(42) << "\n";
}

void test_animal_array() {
	print_header("Testing Animal Array");
	
	const int num_animals = 4;
	Animal* animals[num_animals];

	// Create animals
	for (int i = 0; i < num_animals; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Delete animals
	for (int i = 0; i < num_animals; i++) {
		delete animals[i];
	}
}

int main(void) {
	print_header("Testing Virtual Functions");
	{
		Animal *animal = new Dog();
		Animal *animal1 = new Cat();

		std::cout << "Animal type checking:\n"
				<< "Object 1: " << animal->getType() << "\n"
				<< "Object 2: " << animal1->getType() << "\n\n";

		std::cout << "Animal sounds:\n";
		animal->makeSound();
		animal1->makeSound();

		delete animal;
		delete animal1;
	}

	print_header("Testing Subject Main Implementation");
	{
		Animal* meta = new Animal();
		Animal* j = new Dog();
		Animal* i = new Cat();
		
		std::cout << j->getType() << " \n";
		std::cout << i->getType() << " \n";
		
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	test_brain_functionality();
	test_deep_copies();
	test_animal_array();

	return 0;
}