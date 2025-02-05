/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:11:59 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/05 12:28:59 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv){
	PhoneBook	book;

	while (true){
		printMenu();
		std::string	command;
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0 || command.compare("1") == 0){
			if (!addContact(book)){
				std::cout << RED << BOLD << "⚠️  Unsuccessfull !" << RESET << std::endl;
			}
		}
		if (command.compare("SEARCH") == 0 || command.compare("2") == 0) {
			SearchContact(book);
		}
		if (command.compare("EXIT") == 0 || command.compare("3") == 0){
			exit(0);
		}
	}
	return (0);
}