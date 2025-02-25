/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:41:26 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/25 16:25:50 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _BUREAUOCRAT_
# define _BUREAUOCRAT_

# include <iostream>
# include <exception>

class Bureaucrat{
	private:
		std::string const _name;
		unsigned int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);

		std::string getName(void);
		unsigned int getGrade(void);

		void	increment(void);
		void	decrement(void);

		class GradeTooHighException: std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: std::exception{
			public:
				const char* what() const throw();
		};

};

std::ostream operator<<(std::ostream &os, Bureaucrat &form);

#endif