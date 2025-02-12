/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:23 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/12 14:34:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include <string.h>

int	main(void){
	std::string	brain = "HI THIS IS FUCKEN BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "ADDRESS string           : " << &brain << std::endl;
	std::cout << "ADDRESS stringPTR        : " << stringPTR << std::endl;
	std::cout << "ADDRESS stringREF        : " << &stringPTR << std::endl;

	std::cout << "VALUE string             : " << brain << std::endl;
	std::cout << "VALUE stringPTR          : " << *stringPTR << std::endl;
	std::cout << "VALUE stringREF          : " << stringREF << std::endl;
	
}