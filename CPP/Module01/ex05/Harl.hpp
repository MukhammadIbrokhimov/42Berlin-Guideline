/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:31 by mukibrok          #+#    #+#             */
/*   Updated: 2025/07/09 18:55:04 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// Color definitions
#define RESET      "\033[0m"        // Reset color
#define GREEN      "\033[32m"       // Green text
#define CYAN       "\033[36m"       // Cyan text
#define BLUE       "\033[34m"       // Blue text
#define YELLOW     "\033[33m"       // Yellow text
#define BOLD       "\033[1m"        // Bold text
#define RED        "\033[31m"

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};