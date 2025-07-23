/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:15:44 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/03 19:01:50 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>

#include "Contact.hpp"

# define RESET   "\033[0m"       // Reset color
# define RED     "\033[31m"      // Red text
# define GREEN   "\033[32m"      // Green text
# define YELLOW  "\033[33m"      // Yellow text
# define BLUE    "\033[34m"      // Blue text
# define CYAN    "\033[36m"      // Cyan text
# define BOLD    "\033[1m"       // Bold text
# define UNDERLINE "\033[4m"     // Underlined text
# define MAGENTA "\033[35m"

class PhoneBook{
	private:
		Contact book[8];
		static int quantity;
	
	public:
		PhoneBook();
		~PhoneBook();
		void	add(const Contact &person);
		int	displayValue(int index) const;
		void	displayAll(void) const;
};

void	printMenu();
bool	addContact(PhoneBook &book);
void	is_upper(std::string &command);
void	SearchContact(PhoneBook &book);
std::string formatField(const std::string& str);
