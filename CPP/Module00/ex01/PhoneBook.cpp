/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:18:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/03 19:01:55 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::quantity = 0;

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add(const Contact &person){
	if (quantity < 8){
		book[quantity] = person;
		quantity++;
	}
	else{
		for (int i = 0; i < 7; ++i){
			book[i] = book[i + 1];
		}
		book[7] = person;
	}
}

int PhoneBook::displayValue(int index) const{
	if (index < 0 || index > 7) {
		std::cout << RED << BOLD << "⚠️  Please provide a correct index!" << RESET << std::endl;
		return (1);
	} else {
		std::string	info = book[index].getFirstName();
		if (info.empty()){
			std::cout << YELLOW << BOLD << "⚠️ This Index is Empty" << RESET << std::endl;
			return 1;
		}
		std::cout << CYAN << BOLD;
		std::cout << "===================================" << std::endl;
		std::cout << "📋  CONTACT FOUND  📇 " << std::endl;
		std::cout << "===================================" << RESET << std::endl;
		std::cout << CYAN << BOLD;
		std::cout << "===================================" << std::endl;
		std::cout << "📋  INFORMATION  📇 " << std::endl;
		std::cout << "===================================" << RESET << std::endl;
		std::cout << YELLOW << "👉 First Name: " << RESET;
		std::cout << info << std::endl;

		std::cout << YELLOW << "👉 Last Name: " << RESET;
		std::cout << book[index].getLastName() << std::endl;

		std::cout << YELLOW << "👉 Nickname: " << RESET;
		std::cout << book[index].getNickName() << std::endl;

		std::cout << YELLOW << "📞 Phone Number: " << RESET;
		std::cout << book[index].getPhoneNumber() << std::endl;

		std::cout << YELLOW << "🔒 Secret: " << RESET;
		std::cout << book[index].getDarkestSecret() << std::endl;

		std::cout << GREEN << BOLD << "✅ Displayed contact successfully!" << RESET << std::endl;
	}
	return (0);
}

void	PhoneBook::displayAll(void) const {
	std::cout << MAGENTA << BOLD;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << RESET;

	for (int i = 0; i < 8; i++) {
		if (book[i].getFirstName().empty())
			continue;

		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << formatField(book[i].getFirstName()) << "|";
		std::cout << formatField(book[i].getLastName()) << "|";
		std::cout << formatField(book[i].getNickName()) << "|";
		std::cout << std::endl;
	}
}
