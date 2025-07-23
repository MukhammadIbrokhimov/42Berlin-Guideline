/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:18:29 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/03 18:50:18 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PhoneBook.hpp"

class Contact{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;
		std::string	phone_number;
	public:
		Contact(void);
		~Contact(void);
		void	setData(std::string fname,
							std::string lname,
							std::string nname,
							std::string pnumber,
							std::string secret);
		std::string		getFirstName(void) const;
		std::string		getLastName(void) const;
		std::string		getNickName(void) const;
		std::string		getDarkestSecret(void) const;
		std::string		getPhoneNumber(void) const;
};