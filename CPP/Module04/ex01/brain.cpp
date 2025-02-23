/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:35:16 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 18:39:43 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain(){
	std::cout << "Brain constuctor called!\n";
	for (int i = 0; i < 100; i++){
		ideas[i] = "";
	}
}

Brain::~Brain(){
	std::cout << "Brain Destructor called!\n";
}

Brain::Brain(const Brain &brain){
	std::cout << "Brain copy constuctor called!\n";
	for (int i = 0; i < 100; i++){
		ideas[i] = brain.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain &brain){
	if (this != &brain){
		for (int i = 0; i < 100; i++){
			this->ideas[i] = brain.ideas[i];
		}
	}
	return (*this);
}

std::string Brain::getIdea(int index){
	std::cout << "Brain getter has been called\n";
	return (index < 0 && index > 100) ? "" : ideas[index];
}

void Brain::setIdea(int index, std::string idea){
	if (ideas && (index >= 0 && index < 100)){
		ideas[index] = idea;
	}
	else{
		std::cout << "Brain setter has been called but was unsuccessfull\n";
	}
	std::cout << "Brain setter has been called\n";
}