/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HelperFunctions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:19:45 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/08 12:37:21 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	printMenu()
{
	std::cout << CYAN << BOLD;
	std::cout << "===================================" << std::endl;
	std::cout << "📞  WELCOME TO YOUR PHONEBOOK  📖  " << std::endl;
	std::cout << "===================================" << RESET << std::endl;
	
	std::cout << YELLOW << BOLD << "Please choose an option:" << RESET << std::endl;
	std::cout << GREEN << BOLD << "[1] ADD     " << BLUE << "[2] SEARCH     " << RED << "[3] EXIT" << RESET << std::endl;

	std::cout << CYAN << "-----------------------------------" << RESET << std::endl;
}

bool is_digit(std::string number)
{
	int i = 0;
	while (number[i])
	{
		if (number[i] == '+')
			i++;
		if (!isdigit(number[i]))
			return (false);
		i++;
	}
	return (true);
}

void	is_upper(std::string &command)
{
	int i = 0;
	while (command[i])
	{
		if (islower(command[i]))
			command[i] = toupper(command[i]);
		i++;
	}
}

bool	addContact(PhoneBook& book)
{
	std::string fname, lname, nname, pnumber, secret;

	std::cout << CYAN << BOLD;
	std::cout << "===================================" << std::endl;
	std::cout << "📋  ADD A NEW CONTACT  📇 " << std::endl;
	std::cout << "===================================" << RESET << std::endl;
	
	std::cout << YELLOW << "👉 First Name: " << RESET;
	std::getline(std::cin, fname);

	std::cout << YELLOW << "👉 Last Name: " << RESET;
	std::getline(std::cin, lname);

	std::cout << YELLOW << "👉 Nickname: " << RESET;
	std::getline(std::cin, nname);

	std::cout << YELLOW << "📞 Phone Number: " << RESET;
	std::getline(std::cin, pnumber);

	std::cout << YELLOW << "🔒 Secret: " << RESET;
	std::getline(std::cin, secret);
	if ((fname.empty() || lname.empty())
		|| (nname.empty() || pnumber.empty() || secret.empty())) {
		std::cout << RED << BOLD
						<< "⚠️  Please fill in all the fields!" 
						<< RESET << std::endl;
		return false;
	}
	if (!is_digit(pnumber)){
		std::cout << RED << BOLD
						<< "⚠️  Invalid Number!" 
						<< RESET << std::endl;
		return false;
	}
	Contact contact;
	contact.setData(fname, lname, nname, pnumber, secret);
	book.add(contact);
	std::cout << GREEN << BOLD << "Successfull" << RESET <<std::endl;
	return (true);
}

std::string formatField(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

int ft_atoi(const std::string& str) {
	int result = 0;
	bool negative = false;
	size_t i = 0;

	// Handle leading minus sign for negative numbers
	if (str[0] == '-') {
		negative = true;
		i++;
	}

	for (; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			// Handle invalid characters
			throw std::invalid_argument("Invalid character in string");
		}
		result = result * 10 + (str[i] - '0');
	}
	return negative ? -result : result;
}

void	SearchContact(PhoneBook &book){
	std::cout << CYAN << BOLD;
	std::cout << "===================================" << std::endl;
	std::cout << "🔍  SEARCH FOR A CONTACT  📇 " << std::endl;
	std::cout << "===================================" << RESET << std::endl;
	book.displayAll();
	std::cout << YELLOW << "👉 Please provide the index number of the contact (0-7): " << RESET;
	std::string index_str;
	std::getline(std::cin, index_str);
	for (int i = 0; index_str[i]; i++){
		if (!isdigit(index_str[i])){
			std::cout << RED << "Only Index Number!" << RESET << std::endl;
			return ;
		}
	}
	int index = 0;
	index = ft_atoi(index_str); // Convert string to integer
	book.displayValue(index);
}