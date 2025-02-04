/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:56:40 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/04 20:23:11 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# include <iostream>

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

		void SetContact(const std::string fname, const std::string lname,
						const std::string nname, const std::string pnumber,
						const std::string dsecret){
				first_name = fname;
				last_name = lname;
				nick_name = nname;
				phone_number = pnumber;
				darkest_secret = dsecret;
			}
		
		std::string GetName() const { return first_name; };
		std::string GetLastName() const { return last_name; };
		std::string GetNickName() const { return nick_name; };
		std::string GetPhoneNumber() const { return phone_number; };
		std::string GetSecret() const { return darkest_secret; };
		
};

class PhoneBook{
	private:
		Contact	persons[8];
		int		quantity = 0;

	public:
		PhoneBook(){};
	
	void	AddBook(const Contact &person){
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

	void	DisplayValue(int index){
		if (index < 0 || index > 7)
			std::cout << "Please provide with correct index !!!" << std::endl;
		else{
			std::cout << persons[index].GetName();
			std::cout << persons[index].GetLastName();
			std::cout << persons[index].GetNickName();
			std::cout << persons[index].GetPhoneNumber();
			std::cout << persons[index].GetSecret();
		}
	}
};

int	main(int argc, char **argv)
{
	std::string	command, fname, lname, nname, pnumber, secret;
	PhoneBook	book;

	while (true){
		std::cout <<"Please choose an option" << std::endl;
		std::cout << "ADD  SEARCH  EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD"){
			Contact	contact;
			std::cout << "Please fill the form" << std::endl;
			std::cout << "First name: " << std::endl;
			std::getline(std::cin, fname);
			std::cout << "Last name: " << std::endl;
			std::getline(std::cin, lname);
			std::cout << "Nick name: " << std::endl;
			std::cin >> nname;
			std::cout << "Phone number: " << std::endl;
			std::cin >> pnumber;
			std::cout << "Secret: " << std::endl;
			std::cin >> secret;
			if (fname.empty() || lname.empty() || nname.empty() || pnumber.empty() || secret.empty())
				std::cout << "please fill all the form !!!" << std::endl;
			else
				contact.SetContact(fname, lname, nname, pnumber, secret);
				book.AddBook(contact);
		}
	}
}