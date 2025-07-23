/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:13:31 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/03 18:43:51 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;

	while (1)
	{
		std::string command;
		printMenu();
		std::getline(std::cin, command);
		is_upper(command);
		if (command.compare("ADD") == 0 || command.compare("1") == 0){
			if (!addContact(book)){
				std::cout << RED << BOLD << "⚠️  Unsuccessfull !" << RESET << std::endl;
			}
		}
		if (command.compare("SEARCH") == 0 || command.compare("2") == 0) {
			SearchContact(book);
		}
		if (command.compare("EXIT") == 0 || command.compare("3") == 0){
			return(0);
		}
	}
}

