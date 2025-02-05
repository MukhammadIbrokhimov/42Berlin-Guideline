/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:56:40 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/05 12:27:39 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::AddBook(const Contact &person){
	if (quantity < 8){
		persons[quantity] = person;
		quantity++;
	}
	else{
		for (int i = 0; i < 7; ++i){
			persons[i] = persons[i + 1];
		}
		persons[7] = person;
	}
}

int PhoneBook::DisplayValue(int index){
	if (index < 0 || index > 7) {
		std::cout << RED << BOLD << "⚠️  Please provide a correct index!" << RESET << std::endl;
		return (1);
	} else {
		std::string	info = persons[index].GetName();
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
		std::cout << persons[index].GetLastName() << std::endl;

		std::cout << YELLOW << "👉 Nickname: " << RESET;
		std::cout << persons[index].GetNickName() << std::endl;

		std::cout << YELLOW << "📞 Phone Number: " << RESET;
		std::cout << persons[index].GetPhoneNumber() << std::endl;

		std::cout << YELLOW << "🔒 Secret: " << RESET;
		std::cout << persons[index].GetSecret() << std::endl;

		std::cout << GREEN << BOLD << "✅ Displayed contact successfully!" << RESET << std::endl;
	}
	return (0);
};