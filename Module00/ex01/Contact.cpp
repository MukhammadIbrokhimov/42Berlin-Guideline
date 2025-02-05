/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:03:17 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/05 11:11:55 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void Contact::SetContact(const std::string fname, const std::string lname,
				const std::string nname, const std::string pnumber,
				const std::string dsecret){
	first_name = fname;
	last_name = lname;
	nick_name = nname;
	phone_number = pnumber;
	darkest_secret = dsecret;
}
		
std::string Contact::GetName() const { return first_name; };
std::string Contact::GetLastName() const { return last_name; };
std::string Contact::GetNickName() const { return nick_name; };
std::string Contact::GetPhoneNumber() const { return phone_number; };
std::string Contact::GetSecret() const { return darkest_secret; };