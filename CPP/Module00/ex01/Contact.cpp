/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:09:12 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/03 18:50:47 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setData(std::string fname,
							std::string lname,
							std::string nname,
							std::string pnumber,
							std::string secret){
	first_name = fname;
	last_name = lname;
	nick_name = nname;
	phone_number = pnumber;
	darkest_secret = secret;
}

std::string	Contact::getFirstName(void) const { return first_name; };
std::string	Contact::getLastName(void) const { return last_name; };
std::string	Contact::getNickName(void) const { return nick_name; };
std::string	Contact::getDarkestSecret(void) const { return darkest_secret; };
std::string	Contact::getPhoneNumber(void) const { return phone_number; };