/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:44:20 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/05 12:32:36 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK

# define PHONEBOOK
# define RESET   "\033[0m"       // Reset color
# define RED     "\033[31m"      // Red text
# define GREEN   "\033[32m"      // Green text
# define YELLOW  "\033[33m"      // Yellow text
# define BLUE    "\033[34m"      // Blue text
# define CYAN    "\033[36m"      // Cyan text
# define BOLD    "\033[1m"       // Bold text
# define UNDERLINE "\033[4m"     // Underlined text

# include <iostream>
# include <stdio.h>

class	Contact{

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact(){};

		~Contact(){};

	// SetContact should take parameters
	void SetContact(const std::string fname, const std::string lname,
					const std::string nname, const std::string pnumber,
					const std::string dsecret);

		// Getter methods
		std::string GetName() const;
		std::string GetLastName() const;
		std::string GetNickName() const;
		std::string GetPhoneNumber() const;
		std::string GetSecret() const;
};

class PhoneBook{
	private:
		Contact	persons[8];
		int		quantity = 0;

	public:
		PhoneBook(){};
	
	void	AddBook(const Contact &person);

	int	DisplayValue(int index);
};

void	printMenu();
void	SearchContact(PhoneBook &book);
void	ft_upper(std::string &command);
bool	ftis_digit(std::string number);
bool	addContact(PhoneBook &book);

#endif