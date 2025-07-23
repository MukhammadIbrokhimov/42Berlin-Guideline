/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:31:49 by hta-rezi2         #+#    #+#             */
/*   Updated: 2025/07/06 05:55:51 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// Color definitions
#define RESET      "\033[0m"        // Reset color
#define GREEN      "\033[32m"       // Green text
#define CYAN       "\033[36m"       // Cyan text
#define BLUE       "\033[34m"       // Blue text
#define YELLOW     "\033[33m"       // Yellow text
#define BOLD       "\033[1m"        // Bold text

int main() {
    std::string brain = "HI THIS IS BRAIN";  // Declare and initialize string
    std::string *stringPTR = &brain;          // Pointer to string
    std::string &stringREF = brain;           // Reference to string

    // Print the memory addresses with colors
    std::cout << BOLD << BLUE << "Memory address of string: " << RESET << &brain << std::endl;
    std::cout << BOLD << CYAN << "Memory address held by stringPTR: " << RESET << stringPTR << std::endl;
    std::cout << BOLD << GREEN << "Memory address held by stringREF: " << RESET << &stringREF << std::endl;

    std::cout << std::endl;  // Blank line for separation

    // Print the values with colors
    std::cout << YELLOW << "Value of string: " << RESET << brain << std::endl;
    std::cout << YELLOW << "Value pointed to by stringPTR: " << RESET << *stringPTR << std::endl;
    std::cout << YELLOW << "Value pointed to by stringREF: " << RESET << stringREF << std::endl;

    return 0;
}
