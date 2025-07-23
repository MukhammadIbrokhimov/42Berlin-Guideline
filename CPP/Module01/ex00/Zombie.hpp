/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi2 <hta-rezi2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 18:15:46 by mukhammad-i       #+#    #+#             */
/*   Updated: 2025/07/06 04:09:53 by hta-rezi2        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define RESET   "\033[0m"       // Reset color
# define RED     "\033[31m"      // Red text
# define GREEN   "\033[32m"      // Green text
# define YELLOW  "\033[33m"      // Yellow text
# define BLUE    "\033[34m"      // Blue text
# define CYAN    "\033[36m"      // Cyan text
# define BOLD    "\033[1m"       // Bold text
# define UNDERLINE "\033[4m"     // Underlined text
# define MAGENTA "\033[35m"

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string _name);
        ~Zombie();

        void    announce(void);
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );
